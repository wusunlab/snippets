program test_diag
    use diag
    integer :: i, j
    real(8), dimension(5, 5) :: M = reshape([(i, i = 1, 25)], [5, 5])
    real(8), dimension(5) :: v
    print *, "M = "
    do i = 1, 5
        do j = 1, 5
            write(*, '(f5.1)', advance="no") M(i, j)
        end do
        write(*, '(a)', advance="no") char(10)
    end do
    call diagv(M, v)
    print *, "v = diagv(M) =", char(10), v
end program
