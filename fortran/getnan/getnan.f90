program getnan
    real(8), parameter :: NaN = transfer(z"7ff0000000000001", 1d0)
    print *, "double NaN: transfer(z'7ff0000000000001', 1d0) = ", NaN
end program getnan
