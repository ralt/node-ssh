{
    "targets": [ {
        "target_name": "ssh",
        "sources": [
            "src/ssh.cc",
            "src/main.cc"
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
