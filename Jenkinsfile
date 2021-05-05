def artifactory_repo = "RemoteRepoFromJenkins"
node {
    def server = Artifactory.server "my_artifactory"
    def client = Artifactory.newConanClient()
    def serverName = client.remote.add server: server, repo: artifactory_repo
    stage("Get recipe"){
        echo "Success"
    }

    stage("Test recipe"){
         
    }

    stage("Upload packages"){
    }
}
