# Experimenting with `lit` for IWYU testing

## Install dependencies

### 1. LLVM Integrated Tester
```sh
# from PyPI
$ pip install lit
# or from the LLVM source tree
$ python llvm/utils/lit/lit.py
```

### 2. OutputCheck

Like LLVM's FileCheck but with some extra features

```sh
# from PyPI
$ pip install OutputCheck
# or from source
$ git clone https://github.com/stp/OutputCheck
```

## Running tests

```sh
# Succinct output, verbose failures
lit -s -v -DIWYU=<directory to the IWYU tool> littests
```


## Challenges / TODO / TBD

- `lit` can't handle IWYU's non-zero exit code policy
  - *Current work-around:* use a wrapper script (`utils/wrap.py`)

- `lit`'s *%s* substitution is always absolute, and IWYU needs to be tested with
  both absolute and relative paths. A feature idea to allow this has been raised here:
  http://lists.llvm.org/pipermail/llvm-dev/2018-January/120053.html

- Bootstrap of the testing environment (virtualenv? tox?)

- Portability (`lit` and `OutputCheck` both appear to work on Windows, but we would need
  to make sure it's works smoothly out of the box for all the major platforms:
  Linux, FreeBSD, macOS, Windows)

- Incremental migration of legacy test cases. How?

- Checks for precise line numbers and IWYU summaries
