#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#include "vector.h"

template <typename Type>
class Matrix {
 public:
  Matrix();
  Matrix(size_t rows, size_t columns);
  Matrix(size_t rows, size_t columns, Type fill_value);
  Matrix(const Matrix& matrix);
  virtual ~Matrix();

  size_t Columns() const;
  size_t Rows() const;

  void AddColumnFront(size_t to_add, Type value);
  void AddColumnBack(size_t to_add, Type value);

  void AddRowFront(size_t to_add, Type value);
  void AddRowBack(size_t to_add, Type value);

  void Fill(Type fill_value);
  Matrix<Type> Transpose();

  const Type& At(size_t row, size_t column) const;
  Type& At(size_t row, size_t column);
  void operator=(const Matrix& matrix);
  Vector<Type>& operator[](size_t index);
  const Vector<Type>& operator[](size_t index) const;

 protected:
  Vector<Vector<Type>> matrix_;
  size_t rows_;
  size_t columns_;

  void Build(size_t rows, size_t columns);
};

template <typename Type>
Matrix<Type>::Matrix() {
  rows_ = 0;
  columns_ = 0;
}

template <typename Type>
Matrix<Type>::Matrix(size_t rows, size_t columns) {
  rows_ = 0;
  columns_ = 0;
  Build(rows, columns);
}

template <typename Type>
Matrix<Type>::Matrix(size_t rows, size_t columns, Type fill_value) {
  rows_ = 0;
  columns_ = 0;
  Build(rows, columns);
  Fill(fill_value);
}

template <typename Type>
Matrix<Type>::Matrix(const Matrix& matrix) {
  rows_ = 0;
  columns_ = 0;
  *this = matrix;
}

template <typename Type>
Matrix<Type>::~Matrix() {}

template <typename Type>
void Matrix<Type>::Build(size_t rows, size_t columns) {
  rows_ = rows;
  columns_ = columns;
  matrix_.Resize(rows);
  for (size_t i = 0; i < matrix_.Size(); ++i) {
    matrix_[i].Resize(columns);
  }
}

template <typename Type>
size_t Matrix<Type>::Columns() const {
  return columns_;
}

template <typename Type>
size_t Matrix<Type>::Rows() const {
  return rows_;
}

template <typename Type>
void Matrix<Type>::AddColumnFront(size_t to_add, Type value) {
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < to_add; ++j) {
      matrix_[i].PushFront(value);
    }
  }
  columns_ += to_add;
}

template <typename Type>
void Matrix<Type>::AddColumnBack(size_t to_add, Type value) {
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < to_add; ++j) {
      matrix_[i].PushBack(value);
    }
  }
  columns_ += to_add;
}

template <typename Type>
void Matrix<Type>::AddRowFront(size_t to_add, Type value) {
  Vector<Type> new_row(columns_, value);
  for (size_t i = 0; i < to_add; ++i) {
    matrix_.PushFront(new_row);
  }
  rows_ += to_add;
}

template <typename Type>
void Matrix<Type>::AddRowBack(size_t to_add, Type value) {
  Vector<Type> new_row(columns_, value);
  for (size_t i = 0; i < to_add; ++i) {
    matrix_.PushBack(new_row);
  }
  rows_ += to_add;
}

template <typename Type>
void Matrix<Type>::Fill(Type fill_value) {
  for (size_t i = 0; i < matrix_.Size(); ++i) {
    for (size_t j = 0; j < matrix_[i].Size(); ++j) {
      matrix_[i][j] = fill_value;
    }
  }
}

template <typename Type>
Matrix<Type> Matrix<Type>::Transpose() {
  Matrix<Type> transpose(columns_, rows_);
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < columns_; ++j) {
      transpose[j][i] = matrix_[i][j];
    }
  }
  return transpose;
}

template <typename Type>
Type& Matrix<Type>::At(size_t row, size_t column) {
  assert(row < rows_ && column < columns_);
  return matrix_[row][column];
}

template <typename Type>
const Type& Matrix<Type>::At(size_t row, size_t column) const {
  assert(row < rows_ && column < columns_);
  return matrix_[row][column];
}

template <typename Type>
void Matrix<Type>::operator=(const Matrix& matrix) {
  Build(matrix.Rows(), matrix.Columns());
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < columns_; ++j) {
      matrix_[i][j] = matrix[i][j];
    }
  }
}

template <typename Type>
Vector<Type>& Matrix<Type>::operator[](size_t index) {
  assert(index < rows_);
  return matrix_[index];
}

template <typename Type>
const Vector<Type>& Matrix<Type>::operator[](size_t index) const {
  assert(index < rows_);
  return matrix_[index];
}

#endif