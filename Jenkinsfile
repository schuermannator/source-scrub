pipeline {
    agent { docker { image 'haskell:8.6.3' } }
    stages {
        stage('build') {
            steps {
                sh 'ghc --version'
            }
        }
    }
}
