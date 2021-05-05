def artifactory_repo = "repofromjenkins1"   // local repository supported only here.
def repo_url = 'https://github.com/conan-io/conan-center-index.git'

node {
    def server = Artifactory.server "my_artifactory"
    def client = Artifactory.newConanClient()
    def serverName = client.remote.add server: server, repo: artifactory_repo
    stage("Get recipe"){
        
    }

    stage("Test recipe"){
         echo "Success"
    }

    stage("Upload packages"){
        
    }
}
