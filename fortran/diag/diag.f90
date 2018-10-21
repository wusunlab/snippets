module diag
implicit none
contains

!> @brief  Extract the diagnoal elements from a matrix.
subroutine diagv(M, v)
    real(8), intent(in), dimension(:, :) :: M
    integer :: i
    real(8), intent(out), dimension(size(M, 1)) :: v
    ! note: no error handling of dimension mismatch
    v = [(M(i, i), i = 1, size(M, 1))]
end subroutine

end module

