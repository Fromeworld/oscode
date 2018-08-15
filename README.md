# oscode: Solve oscillatory differential equations with RKWKB 

## Description

Restructured version of cRKWKB.

## Files and dependencies

- `system.hpp`: defines an object that stores information about the system of
  equations being solved such as F, w, g, gradients, Hessians, etc.
- `integrator.hpp`: defines an object each for every method of numerical
  integration available, e.g. RKF, WKB. Each of these has a step method that
  takes one step with the given method.
- `solver.hpp`: defines a solution object.

## Testing

- `test.cpp` is used for testing various features of the RKWKB solver.
- to compile, `make test` (or just `make`)
- to run, `./test`
