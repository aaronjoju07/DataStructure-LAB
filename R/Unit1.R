cbind(c(1,2,3),c(4,5,6))
rbind(c(1,2,3),c(9,3,6))
x=c(1,2,3,4,5,6)
x
class(x)
dim(x) =c(2,3)
x
class(x)
A[c(1,2),c(2)]
A[c(1,2),c(1)]
A[c(1,2)]
A[-1]
A[,]
A[,-1]
A[-1,]
A[1,]
A[,1]
class(A[1,])
y=matrix(c(4,6,1,2,3,6,2,1,2),nrow = 3,ncol = 3,byrow = TRUE)
y
y[c(TRUE,FALSE,TRUE),c(TRUE,TRUE,FALSE)]
y
y[c(TRUE,FALSE),c(2,3)]
y=matrix(c(4,6,1,2,3,6,2,1,2),nrow = 3,ncol = 3,byrow = TRUE,dimnames = list(NULL,c("A","B","C")))
y
y[,"A"]
y[TRUE,c("A","C")]
y[2,2]=10
y
y[y<6]=0
y
y=matrix(c(4,6,1,2,3,6,2,1,2),nrow = 3,ncol = 3,byrow = TRUE)
y
t(y)
cbind(y,c(1,2,3))
rbind(y,c(11,22,33))
y
y=y[1:2]; y
#create 2x2 matrix
A=matrix(c(4,6,1,2),nrow = 2,ncol = 2,byrow = TRUE)
A
B=matrix(c(6,2,1,2),nrow = 2,ncol = 2,byrow = TRUE);B
#Calc sum of matrix A & B
matrix_sum = sum(A,B);matrix_sum
#calc the diff between matrix A & B
matrix_diff = A-B;matrix_diff
#multiply matrix
matrixmul=A*2;matrixmul
#calc product of matrix
matrix_product = prod(A,B);matrix_product
matrix_product = A*B;matrix_product
#transpose od matrix A
matrix_A_transpose = t(A)
#determinant of matrix B
det_B = det(B);det_B
#invert matrix B
matrix_B_invert=solve(B);matrix_B_invert
#if cond

# find transpose of matrix
mat_transpose <- t(B)

# multiply matrix with its transpose
result <- B %*% mat_transpose
if (identical(result, diag(nrow(B)))) {
  print("Given matrix is orthogonal")
} else {
  print("Given matrix is not orthogonal")
}
