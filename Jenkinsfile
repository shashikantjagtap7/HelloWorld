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
    
    stage("Connecting to Test Environment & Download Archives from Jenkins"){
       sh "hostname -I"
       sh "#!/bin/bash"
       sh "pwd"
        // create the abc.zip file.
       sh "wget -O abc.txt --auth-no-challenge --user=admin --password=admin http://localhost:8080/job/artifact%20generator/lastSuccessfulBuild/artifact/*"
       
        sh "sshpass -p 'e3-sdk' ssh -tt -o StrictHostKeyChecking=no developer@192.168.1.100 ls" //list the content in home directory of vmware
        sh "sshpass -p 'e3-sdk' ssh -tt -o StrictHostKeyChecking=no developer@192.168.1.100 ls jenkins"
        sh "sshpass -p 'e3-sdk' scp abc.txt developer@192.168.1.100:jenkins"    // ship abc.txt from localhost to vmware.
        sh "sshpass -p 'e3-sdk' ssh -tt -o StrictHostKeyChecking=no developer@192.168.1.100 ls jenkins" 
    }
    
    stage("Download Artifacts from Artifactory"){
       //sh "curl -sSf -u 'admin:password' -O 'http://localhost:8082/ui/repos/tree/General/repofromjenkins1/hello.zip'"
       sh "pwd"
       sh "sshpass -p 'e3-sdk' ssh -tt -o StrictHostKeyChecking=no developer@192.168.1.100 ./mytrigger.sh"  // trigger the script from virtual m/c. change the ip from script also
        
    }
}
