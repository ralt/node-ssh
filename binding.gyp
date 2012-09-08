{
    "targets": [ {
        "target_name": "ssh",
        "sources": [
            "src/main.cc",
            "src/ssh.cc"
        ],
        "conditions": [ [
            'OS=="linux"', {
                "libraries": [
                    '-lssh2'
                ]
            }
        ]]
    }]
}
