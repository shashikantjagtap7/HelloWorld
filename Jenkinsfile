def artifactory_repo = "repofromjenkins1"   // local repository supported only here.
def repo_url = 'https://github.com/shashikantjagtap7/HelloWorld.git'
def repo_branch = "master"

node {
    def server = Artifactory.server "my_artifactory"
    def client = Artifactory.newConanClient()
    def serverName = client.remote.add server: server, repo: artifactory_repo
    stage("Get recipe"){
        git branch: repo_branch, url: repo_url
    }
    
    stage("Get dependencies and publish build info"){
        sh "mkdir -p build"
        dir ('build') {
          def b = client.run(command: "install ..")
          server.publishBuildInfo b
        }
    }

    stage("Build / Test recipe"){
          sh "conan create ."
          sh "conan build . -if=build -bf=build"
          sh "ls build"
          sh "conan search"
    }

    stage("Upload packages"){
         //String command= sh "upload \"*\" --all -r ${serverName} --confirm"
        //def b = client.run(command: command)
        sh "upload hello/1.0 --all -r ${artifactory_repo} --confirm"      
    }
}
