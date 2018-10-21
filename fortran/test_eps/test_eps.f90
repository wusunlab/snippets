program test_eps
    implicit none
    print *, "Double precision:"
    print *, "epsilon @ 0.0d = ", epsilon(0d0)
    print *, "epsilon @ 1.0d = ", epsilon(1d0)
    print *, "tiny @ 0.0d = ", tiny(0d0)
    print *, "tiny @ 1.0d = ", tiny(1d0)
    print *, "huge @ 0.0d = ", huge(0d0)
    print *, "huge @ 1.0d = ", huge(1d0)

    print *, "Single precision:"
    print *, "epsilon @ 0.0f = ", epsilon(0e0)
    print *, "epsilon @ 1.0f = ", epsilon(1e0)
    print *, "tiny @ 0.0f = ", tiny(0e0)
    print *, "tiny @ 1.0f = ", tiny(1e0)
    print *, "huge @ 0.0f = ", huge(0e0)
    print *, "huge @ 1.0f = ", huge(1e0)
end program test_eps
