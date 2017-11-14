#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <NCollection_Array2.hxx>
#include <FEmTool_AssemblyTable.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <FEmTool_HAssemblyTable.hxx>
#include <PLib_Base.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <FEmTool_Curve.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <FEmTool_ElementaryCriterion.hxx>
#include <TColStd_Array2OfInteger.hxx>
#include <FEmTool_Assembly.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <FEmTool_ListOfVectors.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <FEmTool_SeqOfLinConstr.hxx>
#include <FEmTool_SparseMatrix.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <FEmTool_ProfileMatrix.hxx>
#include <math_FunctionSet.hxx>
#include <FEmTool_ElementsOfRefMatrix.hxx>
#include <GeomAbs_Shape.hxx>
#include <FEmTool_LinearFlexion.hxx>
#include <FEmTool_LinearJerk.hxx>
#include <FEmTool_LinearTension.hxx>

PYBIND11_MODULE(FEmTool, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.PLib");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.math");
	py::module::import("OCCT.GeomAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<FEmTool_AssemblyTable, std::unique_ptr<FEmTool_AssemblyTable, Deleter<FEmTool_AssemblyTable>>> cls_FEmTool_AssemblyTable(mod, "FEmTool_AssemblyTable", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_FEmTool_AssemblyTable.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_FEmTool_AssemblyTable.def(py::init([] (const FEmTool_AssemblyTable &other) {return new FEmTool_AssemblyTable(other);}), "Copy constructor", py::arg("other"));
	cls_FEmTool_AssemblyTable.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_FEmTool_AssemblyTable.def("Init", (void (FEmTool_AssemblyTable::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &FEmTool_AssemblyTable::Init, "Initialise the values", py::arg("theValue"));
	cls_FEmTool_AssemblyTable.def("Size", (Standard_Integer (FEmTool_AssemblyTable::*)() const ) &FEmTool_AssemblyTable::Size, "Size (number of items)");
	cls_FEmTool_AssemblyTable.def("Length", (Standard_Integer (FEmTool_AssemblyTable::*)() const ) &FEmTool_AssemblyTable::Length, "Length (number of items)");
	cls_FEmTool_AssemblyTable.def("RowLength", (Standard_Integer (FEmTool_AssemblyTable::*)() const ) &FEmTool_AssemblyTable::RowLength, "Returns length of the row, i.e. number of columns");
	cls_FEmTool_AssemblyTable.def("ColLength", (Standard_Integer (FEmTool_AssemblyTable::*)() const ) &FEmTool_AssemblyTable::ColLength, "Returns length of the column, i.e. number of rows");
	cls_FEmTool_AssemblyTable.def("LowerRow", (Standard_Integer (FEmTool_AssemblyTable::*)() const ) &FEmTool_AssemblyTable::LowerRow, "LowerRow");
	cls_FEmTool_AssemblyTable.def("UpperRow", (Standard_Integer (FEmTool_AssemblyTable::*)() const ) &FEmTool_AssemblyTable::UpperRow, "UpperRow");
	cls_FEmTool_AssemblyTable.def("LowerCol", (Standard_Integer (FEmTool_AssemblyTable::*)() const ) &FEmTool_AssemblyTable::LowerCol, "LowerCol");
	cls_FEmTool_AssemblyTable.def("UpperCol", (Standard_Integer (FEmTool_AssemblyTable::*)() const ) &FEmTool_AssemblyTable::UpperCol, "UpperCol");
	cls_FEmTool_AssemblyTable.def("IsDeletable", (Standard_Boolean (FEmTool_AssemblyTable::*)() const ) &FEmTool_AssemblyTable::IsDeletable, "myDeletable flag");
	cls_FEmTool_AssemblyTable.def("Assign", (FEmTool_AssemblyTable & (FEmTool_AssemblyTable::*)(const FEmTool_AssemblyTable &)) &FEmTool_AssemblyTable::Assign, "Assignment", py::arg("theOther"));
	cls_FEmTool_AssemblyTable.def("assign", (FEmTool_AssemblyTable & (FEmTool_AssemblyTable::*)(const FEmTool_AssemblyTable &)) &FEmTool_AssemblyTable::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_FEmTool_AssemblyTable.def("Value", (const opencascade::handle<TColStd_HArray1OfInteger> & (FEmTool_AssemblyTable::*)(const Standard_Integer, const Standard_Integer) const ) &FEmTool_AssemblyTable::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_FEmTool_AssemblyTable.def("__call__", (const opencascade::handle<TColStd_HArray1OfInteger> & (FEmTool_AssemblyTable::*)(const Standard_Integer, const Standard_Integer) const ) &FEmTool_AssemblyTable::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_FEmTool_AssemblyTable.def("ChangeValue", (opencascade::handle<TColStd_HArray1OfInteger> & (FEmTool_AssemblyTable::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_AssemblyTable::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_FEmTool_AssemblyTable.def("__call__", (opencascade::handle<TColStd_HArray1OfInteger> & (FEmTool_AssemblyTable::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_AssemblyTable::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_FEmTool_AssemblyTable.def("SetValue", (void (FEmTool_AssemblyTable::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &)) &FEmTool_AssemblyTable::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FEmTool_Curve.hxx
	py::class_<FEmTool_Curve, opencascade::handle<FEmTool_Curve>, Standard_Transient> cls_FEmTool_Curve(mod, "FEmTool_Curve", "Curve defined by Polynomial Elements.");
	cls_FEmTool_Curve.def(py::init<const Standard_Integer, const Standard_Integer, const opencascade::handle<PLib_Base> &, const Standard_Real>(), py::arg("Dimension"), py::arg("NbElements"), py::arg("TheBase"), py::arg("Tolerance"));
	cls_FEmTool_Curve.def("Knots", (TColStd_Array1OfReal & (FEmTool_Curve::*)() const ) &FEmTool_Curve::Knots, "None");
	cls_FEmTool_Curve.def("SetElement", (void (FEmTool_Curve::*)(const Standard_Integer, const TColStd_Array2OfReal &)) &FEmTool_Curve::SetElement, "None", py::arg("IndexOfElement"), py::arg("Coeffs"));
	cls_FEmTool_Curve.def("D0", (void (FEmTool_Curve::*)(const Standard_Real, TColStd_Array1OfReal &)) &FEmTool_Curve::D0, "None", py::arg("U"), py::arg("Pnt"));
	cls_FEmTool_Curve.def("D1", (void (FEmTool_Curve::*)(const Standard_Real, TColStd_Array1OfReal &)) &FEmTool_Curve::D1, "None", py::arg("U"), py::arg("Vec"));
	cls_FEmTool_Curve.def("D2", (void (FEmTool_Curve::*)(const Standard_Real, TColStd_Array1OfReal &)) &FEmTool_Curve::D2, "None", py::arg("U"), py::arg("Vec"));
	cls_FEmTool_Curve.def("Length", (void (FEmTool_Curve::*)(const Standard_Real, const Standard_Real, Standard_Real &)) &FEmTool_Curve::Length, "None", py::arg("FirstU"), py::arg("LastU"), py::arg("Length"));
	cls_FEmTool_Curve.def("GetElement", (void (FEmTool_Curve::*)(const Standard_Integer, TColStd_Array2OfReal &)) &FEmTool_Curve::GetElement, "None", py::arg("IndexOfElement"), py::arg("Coeffs"));
	cls_FEmTool_Curve.def("GetPolynom", (void (FEmTool_Curve::*)(TColStd_Array1OfReal &)) &FEmTool_Curve::GetPolynom, "returns coefficients of all elements in canonical base.", py::arg("Coeffs"));
	cls_FEmTool_Curve.def("NbElements", (Standard_Integer (FEmTool_Curve::*)() const ) &FEmTool_Curve::NbElements, "None");
	cls_FEmTool_Curve.def("Dimension", (Standard_Integer (FEmTool_Curve::*)() const ) &FEmTool_Curve::Dimension, "None");
	cls_FEmTool_Curve.def("Base", (opencascade::handle<PLib_Base> (FEmTool_Curve::*)() const ) &FEmTool_Curve::Base, "None");
	cls_FEmTool_Curve.def("Degree", (Standard_Integer (FEmTool_Curve::*)(const Standard_Integer) const ) &FEmTool_Curve::Degree, "None", py::arg("IndexOfElement"));
	cls_FEmTool_Curve.def("SetDegree", (void (FEmTool_Curve::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_Curve::SetDegree, "None", py::arg("IndexOfElement"), py::arg("Degree"));
	cls_FEmTool_Curve.def("ReduceDegree", (void (FEmTool_Curve::*)(const Standard_Integer, const Standard_Real, Standard_Integer &, Standard_Real &)) &FEmTool_Curve::ReduceDegree, "None", py::arg("IndexOfElement"), py::arg("Tol"), py::arg("NewDegree"), py::arg("MaxError"));
	cls_FEmTool_Curve.def_static("get_type_name_", (const char * (*)()) &FEmTool_Curve::get_type_name, "None");
	cls_FEmTool_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_Curve::get_type_descriptor, "None");
	cls_FEmTool_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_Curve::*)() const ) &FEmTool_Curve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FEmTool_ElementaryCriterion.hxx
	py::class_<FEmTool_ElementaryCriterion, opencascade::handle<FEmTool_ElementaryCriterion>, Standard_Transient> cls_FEmTool_ElementaryCriterion(mod, "FEmTool_ElementaryCriterion", "defined J Criteria to used in minimisation");
	cls_FEmTool_ElementaryCriterion.def("Set", (void (FEmTool_ElementaryCriterion::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &FEmTool_ElementaryCriterion::Set, "Set the coefficient of the Element (the Curve)", py::arg("Coeff"));
	cls_FEmTool_ElementaryCriterion.def("Set", (void (FEmTool_ElementaryCriterion::*)(const Standard_Real, const Standard_Real)) &FEmTool_ElementaryCriterion::Set, "Set the definition interval of the Element", py::arg("FirstKnot"), py::arg("LastKnot"));
	cls_FEmTool_ElementaryCriterion.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_ElementaryCriterion::*)() const ) &FEmTool_ElementaryCriterion::DependenceTable, "To know if two dimension are independent.");
	cls_FEmTool_ElementaryCriterion.def("Value", (Standard_Real (FEmTool_ElementaryCriterion::*)()) &FEmTool_ElementaryCriterion::Value, "To Compute J(E) where E is the current Element");
	cls_FEmTool_ElementaryCriterion.def("Hessian", (void (FEmTool_ElementaryCriterion::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_ElementaryCriterion::Hessian, "To Compute J(E) the coefficients of Hessian matrix of J(E) wich are crossed derivatives in dimensions <Dim1> and <Dim2>. If DependenceTable(Dimension1,Dimension2) is False", py::arg("Dim1"), py::arg("Dim2"), py::arg("H"));
	cls_FEmTool_ElementaryCriterion.def("Gradient", (void (FEmTool_ElementaryCriterion::*)(const Standard_Integer, math_Vector &)) &FEmTool_ElementaryCriterion::Gradient, "To Compute the coefficients in the dimension <dim> of the J(E)'s Gradient where E is the current Element", py::arg("Dim"), py::arg("G"));
	cls_FEmTool_ElementaryCriterion.def_static("get_type_name_", (const char * (*)()) &FEmTool_ElementaryCriterion::get_type_name, "None");
	cls_FEmTool_ElementaryCriterion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_ElementaryCriterion::get_type_descriptor, "None");
	cls_FEmTool_ElementaryCriterion.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_ElementaryCriterion::*)() const ) &FEmTool_ElementaryCriterion::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FEmTool_Assembly.hxx
	py::class_<FEmTool_Assembly, std::unique_ptr<FEmTool_Assembly, Deleter<FEmTool_Assembly>>> cls_FEmTool_Assembly(mod, "FEmTool_Assembly", "Assemble and solve system from (one dimensional) Finite Elements");
	cls_FEmTool_Assembly.def(py::init<const TColStd_Array2OfInteger &, const opencascade::handle<FEmTool_HAssemblyTable> &>(), py::arg("Dependence"), py::arg("Table"));
	cls_FEmTool_Assembly.def("NullifyMatrix", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::NullifyMatrix, "Nullify all Matrix 's Coefficient");
	cls_FEmTool_Assembly.def("AddMatrix", (void (FEmTool_Assembly::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const math_Matrix &)) &FEmTool_Assembly::AddMatrix, "Add an elementary Matrix in the assembly Matrix if Dependence(Dimension1,Dimension2) is False", py::arg("Element"), py::arg("Dimension1"), py::arg("Dimension2"), py::arg("Mat"));
	cls_FEmTool_Assembly.def("NullifyVector", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::NullifyVector, "Nullify all Coordinate of assembly Vector (second member)");
	cls_FEmTool_Assembly.def("AddVector", (void (FEmTool_Assembly::*)(const Standard_Integer, const Standard_Integer, const math_Vector &)) &FEmTool_Assembly::AddVector, "Add an elementary Vector in the assembly Vector (second member)", py::arg("Element"), py::arg("Dimension"), py::arg("Vec"));
	cls_FEmTool_Assembly.def("ResetConstraint", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::ResetConstraint, "Delete all Constraints.");
	cls_FEmTool_Assembly.def("NullifyConstraint", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::NullifyConstraint, "Nullify all Constraints.");
	cls_FEmTool_Assembly.def("AddConstraint", (void (FEmTool_Assembly::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const math_Vector &, const Standard_Real)) &FEmTool_Assembly::AddConstraint, "None", py::arg("IndexofConstraint"), py::arg("Element"), py::arg("Dimension"), py::arg("LinearForm"), py::arg("Value"));
	cls_FEmTool_Assembly.def("Solve", (Standard_Boolean (FEmTool_Assembly::*)()) &FEmTool_Assembly::Solve, "Solve the assembly system Returns Standard_False if the computation failed.");
	cls_FEmTool_Assembly.def("Solution", (void (FEmTool_Assembly::*)(math_Vector &) const ) &FEmTool_Assembly::Solution, "None", py::arg("Solution"));
	cls_FEmTool_Assembly.def("NbGlobVar", (Standard_Integer (FEmTool_Assembly::*)() const ) &FEmTool_Assembly::NbGlobVar, "None");
	cls_FEmTool_Assembly.def("GetAssemblyTable", (void (FEmTool_Assembly::*)(opencascade::handle<FEmTool_HAssemblyTable> &) const ) &FEmTool_Assembly::GetAssemblyTable, "None", py::arg("AssTable"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FEmTool_SparseMatrix.hxx
	py::class_<FEmTool_SparseMatrix, opencascade::handle<FEmTool_SparseMatrix>, Standard_Transient> cls_FEmTool_SparseMatrix(mod, "FEmTool_SparseMatrix", "Sparse Matrix definition");
	cls_FEmTool_SparseMatrix.def("Init", (void (FEmTool_SparseMatrix::*)(const Standard_Real)) &FEmTool_SparseMatrix::Init, "None", py::arg("Value"));
	cls_FEmTool_SparseMatrix.def("ChangeValue", (Standard_Real & (FEmTool_SparseMatrix::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_SparseMatrix::ChangeValue, "None", py::arg("I"), py::arg("J"));
	cls_FEmTool_SparseMatrix.def("Decompose", (Standard_Boolean (FEmTool_SparseMatrix::*)()) &FEmTool_SparseMatrix::Decompose, "To make a Factorization of <me>");
	cls_FEmTool_SparseMatrix.def("Solve", (void (FEmTool_SparseMatrix::*)(const math_Vector &, math_Vector &) const ) &FEmTool_SparseMatrix::Solve, "Direct Solve of AX = B", py::arg("B"), py::arg("X"));
	cls_FEmTool_SparseMatrix.def("Prepare", (Standard_Boolean (FEmTool_SparseMatrix::*)()) &FEmTool_SparseMatrix::Prepare, "Make Preparation to iterative solve");
	cls_FEmTool_SparseMatrix.def("Solve", [](FEmTool_SparseMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3) -> void { return self.Solve(a0, a1, a2, a3); }, py::arg("B"), py::arg("Init"), py::arg("X"), py::arg("Residual"));
	cls_FEmTool_SparseMatrix.def("Solve", [](FEmTool_SparseMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3, const Standard_Real a4) -> void { return self.Solve(a0, a1, a2, a3, a4); }, py::arg("B"), py::arg("Init"), py::arg("X"), py::arg("Residual"), py::arg("Tolerance"));
	cls_FEmTool_SparseMatrix.def("Solve", (void (FEmTool_SparseMatrix::*)(const math_Vector &, const math_Vector &, math_Vector &, math_Vector &, const Standard_Real, const Standard_Integer) const ) &FEmTool_SparseMatrix::Solve, "Iterative solve of AX = B", py::arg("B"), py::arg("Init"), py::arg("X"), py::arg("Residual"), py::arg("Tolerance"), py::arg("NbIterations"));
	cls_FEmTool_SparseMatrix.def("Multiplied", (void (FEmTool_SparseMatrix::*)(const math_Vector &, math_Vector &) const ) &FEmTool_SparseMatrix::Multiplied, "returns the product of a SparseMatrix by a vector. An exception is raised if the dimensions are different", py::arg("X"), py::arg("MX"));
	cls_FEmTool_SparseMatrix.def("RowNumber", (Standard_Integer (FEmTool_SparseMatrix::*)() const ) &FEmTool_SparseMatrix::RowNumber, "returns the row range of a matrix.");
	cls_FEmTool_SparseMatrix.def("ColNumber", (Standard_Integer (FEmTool_SparseMatrix::*)() const ) &FEmTool_SparseMatrix::ColNumber, "returns the column range of the matrix.");
	cls_FEmTool_SparseMatrix.def_static("get_type_name_", (const char * (*)()) &FEmTool_SparseMatrix::get_type_name, "None");
	cls_FEmTool_SparseMatrix.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_SparseMatrix::get_type_descriptor, "None");
	cls_FEmTool_SparseMatrix.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_SparseMatrix::*)() const ) &FEmTool_SparseMatrix::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FEmTool_ElementsOfRefMatrix.hxx
	py::class_<FEmTool_ElementsOfRefMatrix, std::unique_ptr<FEmTool_ElementsOfRefMatrix, Deleter<FEmTool_ElementsOfRefMatrix>>, math_FunctionSet> cls_FEmTool_ElementsOfRefMatrix(mod, "FEmTool_ElementsOfRefMatrix", "this class describes the functions needed for calculating matrix elements of RefMatrix for linear criteriums (Tension, Flexsion and Jerk) by Gauss integration. Each function from set gives value Pi(u)'*Pj(u)' or Pi(u)''*Pj(u)'' or Pi(u)'''*Pj(u)''' for each i and j, where Pi(u) is i-th basis function of expansion and (') means derivative.");
	cls_FEmTool_ElementsOfRefMatrix.def(py::init<const opencascade::handle<PLib_Base> &, const Standard_Integer>(), py::arg("TheBase"), py::arg("DerOrder"));
	cls_FEmTool_ElementsOfRefMatrix.def("NbVariables", (Standard_Integer (FEmTool_ElementsOfRefMatrix::*)() const ) &FEmTool_ElementsOfRefMatrix::NbVariables, "returns the number of variables of the function. It is supposed that NbVariables = 1.");
	cls_FEmTool_ElementsOfRefMatrix.def("NbEquations", (Standard_Integer (FEmTool_ElementsOfRefMatrix::*)() const ) &FEmTool_ElementsOfRefMatrix::NbEquations, "returns the number of equations of the function.");
	cls_FEmTool_ElementsOfRefMatrix.def("Value", (Standard_Boolean (FEmTool_ElementsOfRefMatrix::*)(const math_Vector &, math_Vector &)) &FEmTool_ElementsOfRefMatrix::Value, "computes the values <F> of the functions for the variable <X>. returns True if the computation was done successfully, False otherwise. F contains results only for i<=j in following order: P0*P0, P0*P1, P0*P2... P1*P1, P1*P2,... (upper triangle of matrix {PiPj})", py::arg("X"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FEmTool_LinearFlexion.hxx
	py::class_<FEmTool_LinearFlexion, opencascade::handle<FEmTool_LinearFlexion>, FEmTool_ElementaryCriterion> cls_FEmTool_LinearFlexion(mod, "FEmTool_LinearFlexion", "Criterium of LinearFlexion To Hermit-Jacobi elements");
	cls_FEmTool_LinearFlexion.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));
	cls_FEmTool_LinearFlexion.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_LinearFlexion::*)() const ) &FEmTool_LinearFlexion::DependenceTable, "None");
	cls_FEmTool_LinearFlexion.def("Value", (Standard_Real (FEmTool_LinearFlexion::*)()) &FEmTool_LinearFlexion::Value, "None");
	cls_FEmTool_LinearFlexion.def("Hessian", (void (FEmTool_LinearFlexion::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_LinearFlexion::Hessian, "None", py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
	cls_FEmTool_LinearFlexion.def("Gradient", (void (FEmTool_LinearFlexion::*)(const Standard_Integer, math_Vector &)) &FEmTool_LinearFlexion::Gradient, "None", py::arg("Dimension"), py::arg("G"));
	cls_FEmTool_LinearFlexion.def_static("get_type_name_", (const char * (*)()) &FEmTool_LinearFlexion::get_type_name, "None");
	cls_FEmTool_LinearFlexion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_LinearFlexion::get_type_descriptor, "None");
	cls_FEmTool_LinearFlexion.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_LinearFlexion::*)() const ) &FEmTool_LinearFlexion::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FEmTool_LinearJerk.hxx
	py::class_<FEmTool_LinearJerk, opencascade::handle<FEmTool_LinearJerk>, FEmTool_ElementaryCriterion> cls_FEmTool_LinearJerk(mod, "FEmTool_LinearJerk", "Criterion of LinearJerk To Hermit-Jacobi elements");
	cls_FEmTool_LinearJerk.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));
	cls_FEmTool_LinearJerk.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_LinearJerk::*)() const ) &FEmTool_LinearJerk::DependenceTable, "None");
	cls_FEmTool_LinearJerk.def("Value", (Standard_Real (FEmTool_LinearJerk::*)()) &FEmTool_LinearJerk::Value, "None");
	cls_FEmTool_LinearJerk.def("Hessian", (void (FEmTool_LinearJerk::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_LinearJerk::Hessian, "None", py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
	cls_FEmTool_LinearJerk.def("Gradient", (void (FEmTool_LinearJerk::*)(const Standard_Integer, math_Vector &)) &FEmTool_LinearJerk::Gradient, "None", py::arg("Dimension"), py::arg("G"));
	cls_FEmTool_LinearJerk.def_static("get_type_name_", (const char * (*)()) &FEmTool_LinearJerk::get_type_name, "None");
	cls_FEmTool_LinearJerk.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_LinearJerk::get_type_descriptor, "None");
	cls_FEmTool_LinearJerk.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_LinearJerk::*)() const ) &FEmTool_LinearJerk::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FEmTool_LinearTension.hxx
	py::class_<FEmTool_LinearTension, opencascade::handle<FEmTool_LinearTension>, FEmTool_ElementaryCriterion> cls_FEmTool_LinearTension(mod, "FEmTool_LinearTension", "Criterium of LinearTension To Hermit-Jacobi elements");
	cls_FEmTool_LinearTension.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));
	cls_FEmTool_LinearTension.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_LinearTension::*)() const ) &FEmTool_LinearTension::DependenceTable, "None");
	cls_FEmTool_LinearTension.def("Value", (Standard_Real (FEmTool_LinearTension::*)()) &FEmTool_LinearTension::Value, "None");
	cls_FEmTool_LinearTension.def("Hessian", (void (FEmTool_LinearTension::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_LinearTension::Hessian, "None", py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
	cls_FEmTool_LinearTension.def("Gradient", (void (FEmTool_LinearTension::*)(const Standard_Integer, math_Vector &)) &FEmTool_LinearTension::Gradient, "None", py::arg("Dimension"), py::arg("G"));
	cls_FEmTool_LinearTension.def_static("get_type_name_", (const char * (*)()) &FEmTool_LinearTension::get_type_name, "None");
	cls_FEmTool_LinearTension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_LinearTension::get_type_descriptor, "None");
	cls_FEmTool_LinearTension.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_LinearTension::*)() const ) &FEmTool_LinearTension::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FEmTool_ProfileMatrix.hxx
	py::class_<FEmTool_ProfileMatrix, opencascade::handle<FEmTool_ProfileMatrix>, FEmTool_SparseMatrix> cls_FEmTool_ProfileMatrix(mod, "FEmTool_ProfileMatrix", "Symmetric Sparse ProfileMatrix useful for 1D Finite Element methods");
	cls_FEmTool_ProfileMatrix.def(py::init<const TColStd_Array1OfInteger &>(), py::arg("FirstIndexes"));
	cls_FEmTool_ProfileMatrix.def("Init", (void (FEmTool_ProfileMatrix::*)(const Standard_Real)) &FEmTool_ProfileMatrix::Init, "None", py::arg("Value"));
	cls_FEmTool_ProfileMatrix.def("ChangeValue", (Standard_Real & (FEmTool_ProfileMatrix::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_ProfileMatrix::ChangeValue, "None", py::arg("I"), py::arg("J"));
	cls_FEmTool_ProfileMatrix.def("Decompose", (Standard_Boolean (FEmTool_ProfileMatrix::*)()) &FEmTool_ProfileMatrix::Decompose, "To make a Factorization of <me>");
	cls_FEmTool_ProfileMatrix.def("Solve", (void (FEmTool_ProfileMatrix::*)(const math_Vector &, math_Vector &) const ) &FEmTool_ProfileMatrix::Solve, "Direct Solve of AX = B", py::arg("B"), py::arg("X"));
	cls_FEmTool_ProfileMatrix.def("Prepare", (Standard_Boolean (FEmTool_ProfileMatrix::*)()) &FEmTool_ProfileMatrix::Prepare, "Make Preparation to iterative solve");
	cls_FEmTool_ProfileMatrix.def("Solve", [](FEmTool_ProfileMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3) -> void { return self.Solve(a0, a1, a2, a3); }, py::arg("B"), py::arg("Init"), py::arg("X"), py::arg("Residual"));
	cls_FEmTool_ProfileMatrix.def("Solve", [](FEmTool_ProfileMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3, const Standard_Real a4) -> void { return self.Solve(a0, a1, a2, a3, a4); }, py::arg("B"), py::arg("Init"), py::arg("X"), py::arg("Residual"), py::arg("Tolerance"));
	cls_FEmTool_ProfileMatrix.def("Solve", (void (FEmTool_ProfileMatrix::*)(const math_Vector &, const math_Vector &, math_Vector &, math_Vector &, const Standard_Real, const Standard_Integer) const ) &FEmTool_ProfileMatrix::Solve, "Iterative solve of AX = B", py::arg("B"), py::arg("Init"), py::arg("X"), py::arg("Residual"), py::arg("Tolerance"), py::arg("NbIterations"));
	cls_FEmTool_ProfileMatrix.def("Multiplied", (void (FEmTool_ProfileMatrix::*)(const math_Vector &, math_Vector &) const ) &FEmTool_ProfileMatrix::Multiplied, "returns the product of a SparseMatrix by a vector. An exception is raised if the dimensions are different", py::arg("X"), py::arg("MX"));
	cls_FEmTool_ProfileMatrix.def("RowNumber", (Standard_Integer (FEmTool_ProfileMatrix::*)() const ) &FEmTool_ProfileMatrix::RowNumber, "returns the row range of a matrix.");
	cls_FEmTool_ProfileMatrix.def("ColNumber", (Standard_Integer (FEmTool_ProfileMatrix::*)() const ) &FEmTool_ProfileMatrix::ColNumber, "returns the column range of the matrix.");
	cls_FEmTool_ProfileMatrix.def("IsInProfile", (Standard_Boolean (FEmTool_ProfileMatrix::*)(const Standard_Integer, const Standard_Integer) const ) &FEmTool_ProfileMatrix::IsInProfile, "None", py::arg("i"), py::arg("j"));
	cls_FEmTool_ProfileMatrix.def("OutM", (void (FEmTool_ProfileMatrix::*)() const ) &FEmTool_ProfileMatrix::OutM, "None");
	cls_FEmTool_ProfileMatrix.def("OutS", (void (FEmTool_ProfileMatrix::*)() const ) &FEmTool_ProfileMatrix::OutS, "None");
	cls_FEmTool_ProfileMatrix.def_static("get_type_name_", (const char * (*)()) &FEmTool_ProfileMatrix::get_type_name, "None");
	cls_FEmTool_ProfileMatrix.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_ProfileMatrix::get_type_descriptor, "None");
	cls_FEmTool_ProfileMatrix.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_ProfileMatrix::*)() const ) &FEmTool_ProfileMatrix::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FEmTool_HAssemblyTable.hxx
	py::class_<FEmTool_HAssemblyTable, opencascade::handle<FEmTool_HAssemblyTable>, FEmTool_AssemblyTable, Standard_Transient> cls_FEmTool_HAssemblyTable(mod, "FEmTool_HAssemblyTable", "None");
	cls_FEmTool_HAssemblyTable.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_FEmTool_HAssemblyTable.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const FEmTool_AssemblyTable::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_FEmTool_HAssemblyTable.def(py::init<const FEmTool_AssemblyTable &>(), py::arg("theOther"));
	cls_FEmTool_HAssemblyTable.def("Array2", (const FEmTool_AssemblyTable & (FEmTool_HAssemblyTable::*)() const ) &FEmTool_HAssemblyTable::Array2, "None");
	cls_FEmTool_HAssemblyTable.def("ChangeArray2", (FEmTool_AssemblyTable & (FEmTool_HAssemblyTable::*)()) &FEmTool_HAssemblyTable::ChangeArray2, "None");
	cls_FEmTool_HAssemblyTable.def_static("get_type_name_", (const char * (*)()) &FEmTool_HAssemblyTable::get_type_name, "None");
	cls_FEmTool_HAssemblyTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_HAssemblyTable::get_type_descriptor, "None");
	cls_FEmTool_HAssemblyTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_HAssemblyTable::*)() const ) &FEmTool_HAssemblyTable::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<FEmTool_ListOfVectors, std::unique_ptr<FEmTool_ListOfVectors, Deleter<FEmTool_ListOfVectors>>, NCollection_BaseList> cls_FEmTool_ListOfVectors(mod, "FEmTool_ListOfVectors", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_FEmTool_ListOfVectors.def(py::init<>());
	cls_FEmTool_ListOfVectors.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_FEmTool_ListOfVectors.def(py::init([] (const FEmTool_ListOfVectors &other) {return new FEmTool_ListOfVectors(other);}), "Copy constructor", py::arg("other"));
	cls_FEmTool_ListOfVectors.def("begin", (FEmTool_ListOfVectors::iterator (FEmTool_ListOfVectors::*)() const ) &FEmTool_ListOfVectors::begin, "Returns an iterator pointing to the first element in the list.");
	cls_FEmTool_ListOfVectors.def("end", (FEmTool_ListOfVectors::iterator (FEmTool_ListOfVectors::*)() const ) &FEmTool_ListOfVectors::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_FEmTool_ListOfVectors.def("cbegin", (FEmTool_ListOfVectors::const_iterator (FEmTool_ListOfVectors::*)() const ) &FEmTool_ListOfVectors::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_FEmTool_ListOfVectors.def("cend", (FEmTool_ListOfVectors::const_iterator (FEmTool_ListOfVectors::*)() const ) &FEmTool_ListOfVectors::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_FEmTool_ListOfVectors.def("Size", (Standard_Integer (FEmTool_ListOfVectors::*)() const ) &FEmTool_ListOfVectors::Size, "Size - Number of items");
	cls_FEmTool_ListOfVectors.def("Assign", (FEmTool_ListOfVectors & (FEmTool_ListOfVectors::*)(const FEmTool_ListOfVectors &)) &FEmTool_ListOfVectors::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_FEmTool_ListOfVectors.def("assign", (FEmTool_ListOfVectors & (FEmTool_ListOfVectors::*)(const FEmTool_ListOfVectors &)) &FEmTool_ListOfVectors::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_FEmTool_ListOfVectors.def("Clear", [](FEmTool_ListOfVectors &self) -> void { return self.Clear(); });
	cls_FEmTool_ListOfVectors.def("Clear", (void (FEmTool_ListOfVectors::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &FEmTool_ListOfVectors::Clear, "Clear this list", py::arg("theAllocator"));
	cls_FEmTool_ListOfVectors.def("First", (const opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListOfVectors::*)() const ) &FEmTool_ListOfVectors::First, "First item");
	cls_FEmTool_ListOfVectors.def("First", (opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListOfVectors::*)()) &FEmTool_ListOfVectors::First, "First item (non-const)");
	cls_FEmTool_ListOfVectors.def("Last", (const opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListOfVectors::*)() const ) &FEmTool_ListOfVectors::Last, "Last item");
	cls_FEmTool_ListOfVectors.def("Last", (opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListOfVectors::*)()) &FEmTool_ListOfVectors::Last, "Last item (non-const)");
	cls_FEmTool_ListOfVectors.def("Append", (opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListOfVectors::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &FEmTool_ListOfVectors::Append, "Append one item at the end", py::arg("theItem"));
	cls_FEmTool_ListOfVectors.def("Append", (void (FEmTool_ListOfVectors::*)(const opencascade::handle<TColStd_HArray1OfReal> &, FEmTool_ListOfVectors::Iterator &)) &FEmTool_ListOfVectors::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_FEmTool_ListOfVectors.def("Append", (void (FEmTool_ListOfVectors::*)(FEmTool_ListOfVectors &)) &FEmTool_ListOfVectors::Append, "Append another list at the end", py::arg("theOther"));
	cls_FEmTool_ListOfVectors.def("Prepend", (opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListOfVectors::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &FEmTool_ListOfVectors::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_FEmTool_ListOfVectors.def("Prepend", (void (FEmTool_ListOfVectors::*)(FEmTool_ListOfVectors &)) &FEmTool_ListOfVectors::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_FEmTool_ListOfVectors.def("RemoveFirst", (void (FEmTool_ListOfVectors::*)()) &FEmTool_ListOfVectors::RemoveFirst, "RemoveFirst item");
	cls_FEmTool_ListOfVectors.def("Remove", (void (FEmTool_ListOfVectors::*)(FEmTool_ListOfVectors::Iterator &)) &FEmTool_ListOfVectors::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_FEmTool_ListOfVectors.def("InsertBefore", (opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListOfVectors::*)(const opencascade::handle<TColStd_HArray1OfReal> &, FEmTool_ListOfVectors::Iterator &)) &FEmTool_ListOfVectors::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_FEmTool_ListOfVectors.def("InsertBefore", (void (FEmTool_ListOfVectors::*)(FEmTool_ListOfVectors &, FEmTool_ListOfVectors::Iterator &)) &FEmTool_ListOfVectors::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_FEmTool_ListOfVectors.def("InsertAfter", (opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListOfVectors::*)(const opencascade::handle<TColStd_HArray1OfReal> &, FEmTool_ListOfVectors::Iterator &)) &FEmTool_ListOfVectors::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_FEmTool_ListOfVectors.def("InsertAfter", (void (FEmTool_ListOfVectors::*)(FEmTool_ListOfVectors &, FEmTool_ListOfVectors::Iterator &)) &FEmTool_ListOfVectors::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_FEmTool_ListOfVectors.def("Reverse", (void (FEmTool_ListOfVectors::*)()) &FEmTool_ListOfVectors::Reverse, "Reverse the list");
	cls_FEmTool_ListOfVectors.def("__iter__", [](const FEmTool_ListOfVectors &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<FEmTool_ListIteratorOfListOfVectors, std::unique_ptr<FEmTool_ListIteratorOfListOfVectors, Deleter<FEmTool_ListIteratorOfListOfVectors>>> cls_FEmTool_ListIteratorOfListOfVectors(mod, "FEmTool_ListIteratorOfListOfVectors", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_FEmTool_ListIteratorOfListOfVectors.def(py::init<>());
	cls_FEmTool_ListIteratorOfListOfVectors.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_FEmTool_ListIteratorOfListOfVectors.def("More", (Standard_Boolean (FEmTool_ListIteratorOfListOfVectors::*)() const ) &FEmTool_ListIteratorOfListOfVectors::More, "Check end");
	cls_FEmTool_ListIteratorOfListOfVectors.def("Next", (void (FEmTool_ListIteratorOfListOfVectors::*)()) &FEmTool_ListIteratorOfListOfVectors::Next, "Make step");
	cls_FEmTool_ListIteratorOfListOfVectors.def("Value", (const opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListIteratorOfListOfVectors::*)() const ) &FEmTool_ListIteratorOfListOfVectors::Value, "Constant Value access");
	cls_FEmTool_ListIteratorOfListOfVectors.def("Value", (opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListIteratorOfListOfVectors::*)()) &FEmTool_ListIteratorOfListOfVectors::Value, "Non-const Value access");
	cls_FEmTool_ListIteratorOfListOfVectors.def("ChangeValue", (opencascade::handle<TColStd_HArray1OfReal> & (FEmTool_ListIteratorOfListOfVectors::*)() const ) &FEmTool_ListIteratorOfListOfVectors::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<FEmTool_SeqOfLinConstr, std::unique_ptr<FEmTool_SeqOfLinConstr, Deleter<FEmTool_SeqOfLinConstr>>, NCollection_BaseSequence> cls_FEmTool_SeqOfLinConstr(mod, "FEmTool_SeqOfLinConstr", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_FEmTool_SeqOfLinConstr.def(py::init<>());
	cls_FEmTool_SeqOfLinConstr.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_FEmTool_SeqOfLinConstr.def(py::init([] (const FEmTool_SeqOfLinConstr &other) {return new FEmTool_SeqOfLinConstr(other);}), "Copy constructor", py::arg("other"));
	cls_FEmTool_SeqOfLinConstr.def("begin", (FEmTool_SeqOfLinConstr::iterator (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_FEmTool_SeqOfLinConstr.def("end", (FEmTool_SeqOfLinConstr::iterator (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_FEmTool_SeqOfLinConstr.def("cbegin", (FEmTool_SeqOfLinConstr::const_iterator (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_FEmTool_SeqOfLinConstr.def("cend", (FEmTool_SeqOfLinConstr::const_iterator (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_FEmTool_SeqOfLinConstr.def("Size", (Standard_Integer (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::Size, "Number of items");
	cls_FEmTool_SeqOfLinConstr.def("Length", (Standard_Integer (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::Length, "Number of items");
	cls_FEmTool_SeqOfLinConstr.def("Lower", (Standard_Integer (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::Lower, "Method for consistency with other collections.");
	cls_FEmTool_SeqOfLinConstr.def("Upper", (Standard_Integer (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::Upper, "Method for consistency with other collections.");
	cls_FEmTool_SeqOfLinConstr.def("IsEmpty", (Standard_Boolean (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::IsEmpty, "Empty query");
	cls_FEmTool_SeqOfLinConstr.def("Reverse", (void (FEmTool_SeqOfLinConstr::*)()) &FEmTool_SeqOfLinConstr::Reverse, "Reverse sequence");
	cls_FEmTool_SeqOfLinConstr.def("Exchange", (void (FEmTool_SeqOfLinConstr::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_SeqOfLinConstr::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_FEmTool_SeqOfLinConstr.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &FEmTool_SeqOfLinConstr::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_FEmTool_SeqOfLinConstr.def("Clear", [](FEmTool_SeqOfLinConstr &self) -> void { return self.Clear(); });
	cls_FEmTool_SeqOfLinConstr.def("Clear", (void (FEmTool_SeqOfLinConstr::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &FEmTool_SeqOfLinConstr::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_FEmTool_SeqOfLinConstr.def("Assign", (FEmTool_SeqOfLinConstr & (FEmTool_SeqOfLinConstr::*)(const FEmTool_SeqOfLinConstr &)) &FEmTool_SeqOfLinConstr::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_FEmTool_SeqOfLinConstr.def("assign", (FEmTool_SeqOfLinConstr & (FEmTool_SeqOfLinConstr::*)(const FEmTool_SeqOfLinConstr &)) &FEmTool_SeqOfLinConstr::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_FEmTool_SeqOfLinConstr.def("Remove", (void (FEmTool_SeqOfLinConstr::*)(FEmTool_SeqOfLinConstr::Iterator &)) &FEmTool_SeqOfLinConstr::Remove, "Remove one item", py::arg("thePosition"));
	cls_FEmTool_SeqOfLinConstr.def("Remove", (void (FEmTool_SeqOfLinConstr::*)(const Standard_Integer)) &FEmTool_SeqOfLinConstr::Remove, "Remove one item", py::arg("theIndex"));
	cls_FEmTool_SeqOfLinConstr.def("Remove", (void (FEmTool_SeqOfLinConstr::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_SeqOfLinConstr::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_FEmTool_SeqOfLinConstr.def("Append", (void (FEmTool_SeqOfLinConstr::*)(const FEmTool_ListOfVectors &)) &FEmTool_SeqOfLinConstr::Append, "Append one item", py::arg("theItem"));
	cls_FEmTool_SeqOfLinConstr.def("Append", (void (FEmTool_SeqOfLinConstr::*)(FEmTool_SeqOfLinConstr &)) &FEmTool_SeqOfLinConstr::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_FEmTool_SeqOfLinConstr.def("Prepend", (void (FEmTool_SeqOfLinConstr::*)(const FEmTool_ListOfVectors &)) &FEmTool_SeqOfLinConstr::Prepend, "Prepend one item", py::arg("theItem"));
	cls_FEmTool_SeqOfLinConstr.def("Prepend", (void (FEmTool_SeqOfLinConstr::*)(FEmTool_SeqOfLinConstr &)) &FEmTool_SeqOfLinConstr::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_FEmTool_SeqOfLinConstr.def("InsertBefore", (void (FEmTool_SeqOfLinConstr::*)(const Standard_Integer, const FEmTool_ListOfVectors &)) &FEmTool_SeqOfLinConstr::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_FEmTool_SeqOfLinConstr.def("InsertBefore", (void (FEmTool_SeqOfLinConstr::*)(const Standard_Integer, FEmTool_SeqOfLinConstr &)) &FEmTool_SeqOfLinConstr::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_FEmTool_SeqOfLinConstr.def("InsertAfter", (void (FEmTool_SeqOfLinConstr::*)(FEmTool_SeqOfLinConstr::Iterator &, const FEmTool_ListOfVectors &)) &FEmTool_SeqOfLinConstr::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_FEmTool_SeqOfLinConstr.def("InsertAfter", (void (FEmTool_SeqOfLinConstr::*)(const Standard_Integer, FEmTool_SeqOfLinConstr &)) &FEmTool_SeqOfLinConstr::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_FEmTool_SeqOfLinConstr.def("InsertAfter", (void (FEmTool_SeqOfLinConstr::*)(const Standard_Integer, const FEmTool_ListOfVectors &)) &FEmTool_SeqOfLinConstr::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_FEmTool_SeqOfLinConstr.def("Split", (void (FEmTool_SeqOfLinConstr::*)(const Standard_Integer, FEmTool_SeqOfLinConstr &)) &FEmTool_SeqOfLinConstr::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_FEmTool_SeqOfLinConstr.def("First", (const FEmTool_ListOfVectors & (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::First, "First item access");
	cls_FEmTool_SeqOfLinConstr.def("ChangeFirst", (FEmTool_ListOfVectors & (FEmTool_SeqOfLinConstr::*)()) &FEmTool_SeqOfLinConstr::ChangeFirst, "First item access");
	cls_FEmTool_SeqOfLinConstr.def("Last", (const FEmTool_ListOfVectors & (FEmTool_SeqOfLinConstr::*)() const ) &FEmTool_SeqOfLinConstr::Last, "Last item access");
	cls_FEmTool_SeqOfLinConstr.def("ChangeLast", (FEmTool_ListOfVectors & (FEmTool_SeqOfLinConstr::*)()) &FEmTool_SeqOfLinConstr::ChangeLast, "Last item access");
	cls_FEmTool_SeqOfLinConstr.def("Value", (const FEmTool_ListOfVectors & (FEmTool_SeqOfLinConstr::*)(const Standard_Integer) const ) &FEmTool_SeqOfLinConstr::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_FEmTool_SeqOfLinConstr.def("__call__", (const FEmTool_ListOfVectors & (FEmTool_SeqOfLinConstr::*)(const Standard_Integer) const ) &FEmTool_SeqOfLinConstr::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_FEmTool_SeqOfLinConstr.def("ChangeValue", (FEmTool_ListOfVectors & (FEmTool_SeqOfLinConstr::*)(const Standard_Integer)) &FEmTool_SeqOfLinConstr::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_FEmTool_SeqOfLinConstr.def("__call__", (FEmTool_ListOfVectors & (FEmTool_SeqOfLinConstr::*)(const Standard_Integer)) &FEmTool_SeqOfLinConstr::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_FEmTool_SeqOfLinConstr.def("SetValue", (void (FEmTool_SeqOfLinConstr::*)(const Standard_Integer, const FEmTool_ListOfVectors &)) &FEmTool_SeqOfLinConstr::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_FEmTool_SeqOfLinConstr.def("__iter__", [](const FEmTool_SeqOfLinConstr &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
