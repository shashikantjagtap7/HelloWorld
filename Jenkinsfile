// location of this project is /home/repos/Pipeline
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
          //server.publishBuildInfo b
        }
    }

    stage("Build / Test recipe"){
          sh "conan create . vw/testing"
          sh "conan build . -if=build -bf=build"
          sh "ls build"
          sh "conan remote list"
          sh "conan search"
    }

    stage("Upload packages"){
         //String command= sh "upload \"*\" --all -r ${serverName} --confirm"
        //def b = client.run(command: command)
        sh " printf 'yes\nyes\nadmin\npassword' | conan upload hello* -r artifactory --all"
    }
    
    stage("Connecting to Test Environment"){
       sh "#!/bin/bash"
       sh "sshpass -p 'e3-sdk' ssh -o StrictHostKeyChecking=no developer@127.0.0.1 -p 2222"
       sh "pwd"
       sh "whoami"
    }
}
