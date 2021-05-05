def artifactory_repo = "repofromjenkins1"   // local repository supported only here.
def repo_url = 'https://github.com/shashikantjagtap7/HelloWorld.git'
def repo_branch = "master"
def recipe_folder = "/var/lib/jenkins/workspace/HelloWorldUploadPipeLine"
def recipe_version = "1.o"

node {
    def server = Artifactory.server "my_artifactory"
    def client = Artifactory.newConanClient()
    def serverName = client.remote.add server: server, repo: artifactory_repo
    stage("Get recipe"){
        git branch: repo_branch, url: repo_url
              echo pwd
              echo ls
    }

    stage("Test recipe"){
         dir (recipe_folder) {

          //client.run(command: "create . ${recipe_version}@")
        }
    }

    stage("Upload packages"){
        echo "Success"
    }
}
