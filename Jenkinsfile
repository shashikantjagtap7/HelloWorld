def artifactory_name = "artifactory"
def artifactory_repo = "conan-local"
def repo_url = 'https://github.com/conan-io/conan-center-index.git'
def repo_branch = "master"
def recipe_folder = "recipes/zlib/1.2.11"
def recipe_version = "1.2.11"

node {
    def server = Artifactory.server artifactory_name
    def client = Artifactory.newConanClient()
    def serverName = client.remote.add server: server, repo: artifactory_repo

    stage("Get recipe"){
        git branch: repo_branch, url: repo_url
    }

    stage("Test recipe"){
        dir (recipe_folder) {
          client.run(command: "create . ${recipe_version}@")
        }
    }

    stage("Upload packages"){
        String command = "upload \"*\" --all -r ${serverName} --confirm"
        def b = client.run(command: command)
        server.publishBuildInfo b
    }
}
