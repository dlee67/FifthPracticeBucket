FROM golang:1.8

ENV SOURCES /go/src

# Notice the connection between the above and the below.
COPY . ${SOURCES}

RUN cd ${SOURCES} && CGO_ENABLED=0 go build hello-cloud.go

ENV PORT 8080
# Despite how it looks like, EXPOSE is a meta data.
EXPOSE 8080

CMD /go/src/hello-cloud