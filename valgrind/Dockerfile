FROM alpine:latest

# Install dependencies
RUN apk update && apk add valgrind gcc g++ make

# docker build . -t foyezar/valgrind:1.0
# docker run -it --rm -v $PWD:/valgrind -w /valgrind --name valgrind foyezar/valgrind:1.0

# docker run -it — this will run your docker container interactively
# --rm — this will remove the container after it exits
# -v $PWD:/valgrind — this will mount your current directory to /valgrind inside the container
# -w /valgrind — this will set the containers working directory to /valgrind
# foyezar/valgrind:1.0 — this is the name and tag of the docker image we created

# alias valgrind='docker run -it -v $PWD:/valgrind -w /valgrind --name valgrind foyezar/valgrind:1.0'

# docker start -i valgrind