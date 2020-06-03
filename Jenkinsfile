pipeline 
{
    agent any
    stages 
    {
        stage("Build")
        {
            steps{
                sh '''
                    echo "Building project"
                    cmakeBuild buildDir: 'build', buildType: 'Release', cleanBuild: true, installation: 'InSearchPath', steps: [[withCmake: true]]
                '''
            }
        }
        stage("Run Google Test")
        {
            steps{
                sh '''
                    echo "Starting google test"
                    build/test/UnitTests --gtest_output="xml:testresults.xml"
                '''
            }
        }
    }
    post 
    {
        always {
            archiveArtifacts 'testresults.xml'
            cleanWs()
        }
        failure {
            archiveArtifacts 'testresults.xml'
        }
    }
}