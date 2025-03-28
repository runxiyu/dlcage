# dlcage – demo on using non-reentrant libraries in multi-threaded contexts

Many programs that may sometimes be used as shared libraries are not reentrant.
However, it is possible to use them safely with POSIX threads, by using
`dlmopen` with `LM_ID_NEWLM`, to load separate copies of the library in
separate linker namespaces.

## Portability

- `dlmopen` is a GNU extension. It could potentially be replaced by
  a variant of [hax_loader](https://forge.runxiyu.org/hax/:/repos/hax_loader/)?
- `typeof` is a GNU extension. It could be avoided by using macros.

## Contribute

Create a branch that begins with `contrib/` and push to
[the repo on our home forge](https://forge.runxiyu.org/stuff/:/repos/dlcage/)
via SSH.

```
git clone ssh://forge.runxiyu.org/stuff/:/repos/dlcage/
cd dlcage
git checkout -b contrib/whatever
# edit and commit stuff
git push -u origin HEAD
```

Pushes that update branches in other namespaces, or pushes to existing
contribution branches belonging to other SSH keys, will be automatically
rejected. Otherwise, a merge request is automatically opened, and the
maintainers are notified via IRC.
