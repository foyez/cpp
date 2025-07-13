# 42

## Useful links

- [42 Core Curriculum](https://github.com/f-corvaro/42.common_core)
- [42 Cursus Guide](https://42-cursus.gitbook.io/guide/)
- [42 Cursus github](https://github.com/thebrisly/42_Cursus-Piscine)
- [42 Evaluation Sheets](https://web.archive.org/web/20240806235651/https://42evals.com/)

## 42 iMac

- To store Docker data in `goinfre` directory to save your home directory

```sh
cd ~/goinfre
mkdir -p $USER/Containers
cp -r ~/Library/Containers/com.docker.docker .

# then, open Docker Desktop Settings and navigate to: Resources > ADVANCED
# now, change Disk image location with: /goinfre/kaahmed/kaahmed/Containers/com.docker.docker/Data/vms/0/data
```

- To reset Home directory

```sh
touch ~/.reset
# restart the iMac
```