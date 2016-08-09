#!/usr/bin/python -tt

import sys, os 

def option():
  print '                 BlackBox enabler               '
  print '              waiting for hand shake            '
  getUser()

def getUser():
  infoDownloader(sys.argv[1])  

def infoDownloader(user_name):
  download_path_cloud=   user_name + '.txt'
  download_path_local = '/home/debjyoti/black_box/'
  path = '/home/debjyoti/black_box/dropbox_uploader.sh download ' + ' ' + download_path_cloud
  #print path
  os.system(path)
  open_file(download_path_cloud, download_path_local)


def open_file(file_name, local_path):
  print '--------------------Address---------------'
  f = open(file_name, 'rU')
  for line in f:
    print line,

  f.close()
  #os.remove(local_path)

def main():
  option()

if __name__=='__main__':
  main()
