// Copyright (C) 2015, Baidu Inc.
// Author: likang01@@baidu.com
//
// Description:  nfs wrapper

#ifndef  TERA_DEPS_NFS_WRAPPER_H
#define  TERA_DEPS_NFS_WRAPPER_H

#include "version.h"

#include "nfs.h"

namespace nfs {
struct NFSFILE;
struct NFSDIR;
};

#ifdef __cplusplus
extern  "C" {
#endif

void InitKylinLog(int loglevel);

void SetComlogLevel(int loglevel);

int GetErrno();

void Perror(const char* s = NULL);

int Init(const char* mountpoint, const char* _config_file_path);

int Access(const char* path, int mode);

int Mkdir(const char* path);

int Rmdir(const char* path);

nfs::NFSDIR* Opendir(const char* path);

struct ::dirent* Readdir(nfs::NFSDIR* dir);

int Closedir(nfs::NFSDIR* dir);

int Create(const char* path);

int Unlink(const char* path);

nfs::NFSFILE* Open(const char* path, const char* mode);

int Close(nfs::NFSFILE* stream);

ssize_t Read(nfs::NFSFILE* stream, void* ptr, size_t size);

ssize_t PRead(nfs::NFSFILE* stream, void* ptr, size_t size, uint64_t offset);

ssize_t Write(nfs::NFSFILE* stream, const void* ptr, size_t size);

int Fsync(nfs::NFSFILE* stream);

int64_t Tell(nfs::NFSFILE* stream);

int Seek(nfs::NFSFILE* stream, uint64_t offset);

int Rename(const char* oldpath, const char* newpath);

int Stat(const char* path, struct ::stat* stat);

#ifdef __cplusplus
}
#endif

#endif  // TERA_DEPS_NFS_WRAPPER_H

