class Matrix
{
public:

    // Creates an empty matrix of size 0 times 0.
    Matrix();

    // Creates an identity matrix of size <size> times <size>.
    Matrix(int size);

    // Creates a matrix of size <height> times <width> filled with 0s.
    Matrix(int height, int width);

    // Copy constructor
    Matrix(const Matrix&);

    // Move constructor
    Matrix(Matrix&&);

    // Destructor
    ~Matrix();


    int getWidth() const;
    int getHeight() const;

    void resize(int height, int width);

    void transpose();


    // Copy assignment
    Matrix& operator=(const Matrix&);

    // Move assignment
    Matrix& operator=(Matrix&&);


    // Returns the value at the specified position in the matrix.
    double& operator()(const int row, const int col);
    double operator()(const int row, const int col) const;


    // Determines if two matrices are equal.
    bool operator==(const Matrix&) const;

private:
    int width;
    int height;

    double** values;
};
