package com.example.tp.math;

import java.lang.System.Logger.Level;
import java.util.Arrays;
import java.util.StringJoiner;

public class Matrix {

	private double[][] coeffs;

	public Matrix(int nbRows, int nbColumns) {
		if (nbRows > 0 && nbColumns > 0) {
			this.coeffs = new double[nbRows][nbColumns];
			for (int i = 0; i < this.coeffs.length; i++) {
				for (int j = 0; j < this.coeffs[i].length; j++) {
					this.coeffs[i][j] = 0.0;
				}
			}
		} else {
			this.coeffs = new double[0][0];
		}
	}

	public Matrix(double[][] m) {
		this(m.length, m[0].length);
		coeffs = Arrays.copyOf(m, m.length);
		for (int i = 0; i < m.length; i++) {
			coeffs[i] = Arrays.copyOf(m[i], m[i].length);
		}
	}

	public Matrix(Matrix src) {
		this(src.getNbRows(), src.getNbColumns());
		for (int i = 0; i < src.getNbRows(); i++) {
			for (int j = 0; j < src.getNbColumns(); j++) {
				this.set(i, j, src.get(i, j));
			}
		}
	}

	public double sum() {
		var acc = 0.0;
		for (var ds : coeffs) {
			for (var d : ds) {
				acc += d;
			}
		}
		return acc;
	}

	public boolean allPositive() {
		for (var ds : coeffs) {
			for (var d : ds) {
				if (d < 0)
					return false;
			}
		}
		return true;
	}

	public Matrix product(Matrix matrix) {
		if (this.getNbRows() != matrix.getNbColumns() || this.getNbColumns() != matrix.getNbRows())
			return null;

		var m = new Matrix(getNbRows(), matrix.getNbColumns());

		for (var i = 0; i < m.getNbColumns(); i++) {
			for (var j = 0; j < m.getNbRows(); j++) {
				var acc = 0.0;
				for (var k = 0; k < matrix.getNbRows(); k++) {
					var a = get(j, k);
					var b = matrix.get(k, i);
					acc += a * b;
				}
				m.set(j, i, acc);
			}
		}
		return m;
	}

	public int getNbRows() {
		return this.coeffs.length;
	}

	public int getNbColumns() {
		if (this.getNbRows() > 0) {
			return this.coeffs[0].length;
		} else {
			return 0;
		}
	}

	public double get(int row, int column) {
		if (row < 0 || row >= this.getNbRows() || column < 0
				|| column >= this.getNbColumns()) {
			return Double.POSITIVE_INFINITY;
		} else {
			return this.coeffs[row][column];
		}
	}

	public void set(int row, int column, double value) {
		if (row >= 0 && row < this.getNbRows() && column >= 0
				&& column < this.getNbColumns()) {
			this.coeffs[row][column] = value;
		}
	}

	public String toString() {
		var s = new StringJoiner("\t");
		for (int i = 0; i < this.getNbRows(); i++) {
			for (int j = 0; j < this.getNbColumns(); j++) {
				s.add(("" + this.get(i, j)));
			}
			s.add("\n");
		}
		return s.toString();
	}

	public static void main(String[] args) {
		var logger = System.getLogger("main");
		Matrix m1 = new Matrix(2, 3);
		m1.set(0, 0, 1.1);
		m1.set(0, 1, 1.2);
		m1.set(0, 2, -1.3);
		m1.set(1, 0, -2.1);
		m1.set(1, 1, 2.2);
		m1.set(1, 2, 2.3);
		double[][] tab = { { 1.1, 1.2 }, { -2.1, 2.2 }, { 3.1, 3.2 } };
		Matrix m2 = new Matrix(tab);
		logger.log(Level.INFO, m2);

		logger.log(Level.INFO, m1.product(m2));

	}
}