#!/bin/sh

WORK_DIR=~

cd $WORK_DIR

# Install IPFS
wget https://dist.ipfs.tech/kubo/v0.15.0/kubo_v0.15.0_linux-amd64.tar.gz
tar -xvzf kubo_v0.15.0_linux-amd64.tar.gz
cd kubo
sudo bash install.sh

cd $WORK_DIR
rm -rf kubo*

# Setup IPFS private network
ipfs init
ipfs bootstrap rm --all

# Fetch swarm key from master
scp peirong3@10.10.1.1:~/.ipfs/swarm.key ~/.ipfs
ipfs bootstrap add /ip4/10.10.1.1/tcp/4001/ipfs/12D3KooWSzjdTDMXepEdUswqoS36Gzdq33CEeQrXFMcwuvp1vwWn

# Disable local caching
ipfs config Datestore.StorageGCWatermark 0
ipfs config Datestore.StorageMax 0GB

bash -c "export LIBP2P_FORCE_PNET=1"

ipfs daemon --enable-gc
