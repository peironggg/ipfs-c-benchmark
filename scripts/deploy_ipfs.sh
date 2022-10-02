#!/bin/bash

# Usage: ./deploy_ipfs.sh
# Run this script after setup_ipfs_master.sh
# It requires that the master node has been set up with IPFS.

nodesIP=("10.10.1.2" "10.10.1.3")

setup_bin=~/ipfs_c_client/scripts/setup_ipfs_worker.sh
chmod +x $setup_bin

# Grab peer ID of master node
peerID=`ipfs id | grep 'ID' | cut -d':' -f2 | cut -d'"' -f2`

for nodeIP in ${nodes[@]}; do
  ssh $nodeIP 'bash -s' < $setup_bin $peerID $nodeIP
done