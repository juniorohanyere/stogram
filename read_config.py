# opens configuration file and gets its content
# the configuration file is something close to headers files in some
# programming languages

def config(cfile="conf.sto"):
    with open(cfile, "r") as file:
        lines = file.readlines()
    line = [ln.strip() for ln in lines]

    return (line)


# reads the configuration for validation

def rconf():
    category = ["[MALE]", "[FEMALE]"]
    line = config()

    for search in category:
        if search in line:
            return (True)
    return (False)
