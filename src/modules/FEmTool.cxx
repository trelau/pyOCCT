/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <NCollection_Array2.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <FEmTool_AssemblyTable.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Std.hxx>
#include <FEmTool_HAssemblyTable.hxx>
#include <Standard_Type.hxx>
#include <NCollection_List.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <FEmTool_ListOfVectors.hxx>
#include <NCollection_Sequence.hxx>
#include <FEmTool_SeqOfLinConstr.hxx>
#include <TColStd_Array2OfInteger.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <FEmTool_ProfileMatrix.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <FEmTool_Assembly.hxx>
#include <PLib_Base.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <FEmTool_Curve.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <FEmTool_ElementaryCriterion.hxx>
#include <math_FunctionSet.hxx>
#include <FEmTool_ElementsOfRefMatrix.hxx>
#include <GeomAbs_Shape.hxx>
#include <FEmTool_LinearFlexion.hxx>
#include <FEmTool_LinearJerk.hxx>
#include <FEmTool_LinearTension.hxx>
#include <FEmTool_SparseMatrix.hxx>
#include <bind_NCollection_Array2.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(FEmTool, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");
py::module::import("OCCT.PLib");
py::module::import("OCCT.GeomAbs");

// TYPEDEF: FEMTOOL_ASSEMBLYTABLE
bind_NCollection_Array2<opencascade::handle<TColStd_HArray1OfInteger> >(mod, "FEmTool_AssemblyTable", py::module_local(false));

// CLASS: FEMTOOL_HASSEMBLYTABLE
py::class_<FEmTool_HAssemblyTable, opencascade::handle<FEmTool_HAssemblyTable>, Standard_Transient> cls_FEmTool_HAssemblyTable(mod, "FEmTool_HAssemblyTable", "None", py::multiple_inheritance());

// Constructors
cls_FEmTool_HAssemblyTable.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_FEmTool_HAssemblyTable.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const FEmTool_AssemblyTable::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_FEmTool_HAssemblyTable.def(py::init<const FEmTool_AssemblyTable &>(), py::arg("theOther"));

// Methods
// cls_FEmTool_HAssemblyTable.def_static("operator new_", (void * (*)(size_t)) &FEmTool_HAssemblyTable::operator new, "None", py::arg("theSize"));
// cls_FEmTool_HAssemblyTable.def_static("operator delete_", (void (*)(void *)) &FEmTool_HAssemblyTable::operator delete, "None", py::arg("theAddress"));
// cls_FEmTool_HAssemblyTable.def_static("operator new[]_", (void * (*)(size_t)) &FEmTool_HAssemblyTable::operator new[], "None", py::arg("theSize"));
// cls_FEmTool_HAssemblyTable.def_static("operator delete[]_", (void (*)(void *)) &FEmTool_HAssemblyTable::operator delete[], "None", py::arg("theAddress"));
// cls_FEmTool_HAssemblyTable.def_static("operator new_", (void * (*)(size_t, void *)) &FEmTool_HAssemblyTable::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FEmTool_HAssemblyTable.def_static("operator delete_", (void (*)(void *, void *)) &FEmTool_HAssemblyTable::operator delete, "None", py::arg(""), py::arg(""));
// cls_FEmTool_HAssemblyTable.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &FEmTool_HAssemblyTable::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_FEmTool_HAssemblyTable.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &FEmTool_HAssemblyTable::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_FEmTool_HAssemblyTable.def("Array2", (const FEmTool_AssemblyTable & (FEmTool_HAssemblyTable::*)() const) &FEmTool_HAssemblyTable::Array2, "None");
cls_FEmTool_HAssemblyTable.def("ChangeArray2", (FEmTool_AssemblyTable & (FEmTool_HAssemblyTable::*)()) &FEmTool_HAssemblyTable::ChangeArray2, "None");
cls_FEmTool_HAssemblyTable.def_static("get_type_name_", (const char * (*)()) &FEmTool_HAssemblyTable::get_type_name, "None");
cls_FEmTool_HAssemblyTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_HAssemblyTable::get_type_descriptor, "None");
cls_FEmTool_HAssemblyTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_HAssemblyTable::*)() const) &FEmTool_HAssemblyTable::DynamicType, "None");

// TYPEDEF: FEMTOOL_LISTOFVECTORS
bind_NCollection_List<opencascade::handle<TColStd_HArray1OfReal> >(mod, "FEmTool_ListOfVectors", py::module_local(false));

// TYPEDEF: FEMTOOL_LISTITERATOROFLISTOFVECTORS
bind_NCollection_TListIterator<opencascade::handle<TColStd_HArray1OfReal> >(mod, "FEmTool_ListIteratorOfListOfVectors", py::module_local(false));

// TYPEDEF: FEMTOOL_SEQOFLINCONSTR
bind_NCollection_Sequence<NCollection_List<opencascade::handle<TColStd_HArray1OfReal> > >(mod, "FEmTool_SeqOfLinConstr", py::module_local(false));

// CLASS: FEMTOOL_ASSEMBLY
py::class_<FEmTool_Assembly> cls_FEmTool_Assembly(mod, "FEmTool_Assembly", "Assemble and solve system from (one dimensional) Finite Elements");

// Constructors
cls_FEmTool_Assembly.def(py::init<const TColStd_Array2OfInteger &, const opencascade::handle<FEmTool_HAssemblyTable> &>(), py::arg("Dependence"), py::arg("Table"));

// Methods
// cls_FEmTool_Assembly.def_static("operator new_", (void * (*)(size_t)) &FEmTool_Assembly::operator new, "None", py::arg("theSize"));
// cls_FEmTool_Assembly.def_static("operator delete_", (void (*)(void *)) &FEmTool_Assembly::operator delete, "None", py::arg("theAddress"));
// cls_FEmTool_Assembly.def_static("operator new[]_", (void * (*)(size_t)) &FEmTool_Assembly::operator new[], "None", py::arg("theSize"));
// cls_FEmTool_Assembly.def_static("operator delete[]_", (void (*)(void *)) &FEmTool_Assembly::operator delete[], "None", py::arg("theAddress"));
// cls_FEmTool_Assembly.def_static("operator new_", (void * (*)(size_t, void *)) &FEmTool_Assembly::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FEmTool_Assembly.def_static("operator delete_", (void (*)(void *, void *)) &FEmTool_Assembly::operator delete, "None", py::arg(""), py::arg(""));
cls_FEmTool_Assembly.def("NullifyMatrix", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::NullifyMatrix, "Nullify all Matrix 's Coefficient");
cls_FEmTool_Assembly.def("AddMatrix", (void (FEmTool_Assembly::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const math_Matrix &)) &FEmTool_Assembly::AddMatrix, "Add an elementary Matrix in the assembly Matrix if Dependence(Dimension1,Dimension2) is False", py::arg("Element"), py::arg("Dimension1"), py::arg("Dimension2"), py::arg("Mat"));
cls_FEmTool_Assembly.def("NullifyVector", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::NullifyVector, "Nullify all Coordinate of assembly Vector (second member)");
cls_FEmTool_Assembly.def("AddVector", (void (FEmTool_Assembly::*)(const Standard_Integer, const Standard_Integer, const math_Vector &)) &FEmTool_Assembly::AddVector, "Add an elementary Vector in the assembly Vector (second member)", py::arg("Element"), py::arg("Dimension"), py::arg("Vec"));
cls_FEmTool_Assembly.def("ResetConstraint", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::ResetConstraint, "Delete all Constraints.");
cls_FEmTool_Assembly.def("NullifyConstraint", (void (FEmTool_Assembly::*)()) &FEmTool_Assembly::NullifyConstraint, "Nullify all Constraints.");
cls_FEmTool_Assembly.def("AddConstraint", (void (FEmTool_Assembly::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const math_Vector &, const Standard_Real)) &FEmTool_Assembly::AddConstraint, "None", py::arg("IndexofConstraint"), py::arg("Element"), py::arg("Dimension"), py::arg("LinearForm"), py::arg("Value"));
cls_FEmTool_Assembly.def("Solve", (Standard_Boolean (FEmTool_Assembly::*)()) &FEmTool_Assembly::Solve, "Solve the assembly system Returns Standard_False if the computation failed.");
cls_FEmTool_Assembly.def("Solution", (void (FEmTool_Assembly::*)(math_Vector &) const) &FEmTool_Assembly::Solution, "None", py::arg("Solution"));
cls_FEmTool_Assembly.def("NbGlobVar", (Standard_Integer (FEmTool_Assembly::*)() const) &FEmTool_Assembly::NbGlobVar, "None");
cls_FEmTool_Assembly.def("GetAssemblyTable", (void (FEmTool_Assembly::*)(opencascade::handle<FEmTool_HAssemblyTable> &) const) &FEmTool_Assembly::GetAssemblyTable, "None", py::arg("AssTable"));

// CLASS: FEMTOOL_CURVE
py::class_<FEmTool_Curve, opencascade::handle<FEmTool_Curve>, Standard_Transient> cls_FEmTool_Curve(mod, "FEmTool_Curve", "Curve defined by Polynomial Elements.");

// Constructors
cls_FEmTool_Curve.def(py::init<const Standard_Integer, const Standard_Integer, const opencascade::handle<PLib_Base> &, const Standard_Real>(), py::arg("Dimension"), py::arg("NbElements"), py::arg("TheBase"), py::arg("Tolerance"));

// Methods
cls_FEmTool_Curve.def("Knots", (TColStd_Array1OfReal & (FEmTool_Curve::*)() const) &FEmTool_Curve::Knots, "None");
cls_FEmTool_Curve.def("SetElement", (void (FEmTool_Curve::*)(const Standard_Integer, const TColStd_Array2OfReal &)) &FEmTool_Curve::SetElement, "None", py::arg("IndexOfElement"), py::arg("Coeffs"));
cls_FEmTool_Curve.def("D0", (void (FEmTool_Curve::*)(const Standard_Real, TColStd_Array1OfReal &)) &FEmTool_Curve::D0, "None", py::arg("U"), py::arg("Pnt"));
cls_FEmTool_Curve.def("D1", (void (FEmTool_Curve::*)(const Standard_Real, TColStd_Array1OfReal &)) &FEmTool_Curve::D1, "None", py::arg("U"), py::arg("Vec"));
cls_FEmTool_Curve.def("D2", (void (FEmTool_Curve::*)(const Standard_Real, TColStd_Array1OfReal &)) &FEmTool_Curve::D2, "None", py::arg("U"), py::arg("Vec"));
cls_FEmTool_Curve.def("Length", [](FEmTool_Curve &self, const Standard_Real FirstU, const Standard_Real LastU, Standard_Real & Length){ self.Length(FirstU, LastU, Length); return Length; }, "None", py::arg("FirstU"), py::arg("LastU"), py::arg("Length"));
cls_FEmTool_Curve.def("GetElement", (void (FEmTool_Curve::*)(const Standard_Integer, TColStd_Array2OfReal &)) &FEmTool_Curve::GetElement, "None", py::arg("IndexOfElement"), py::arg("Coeffs"));
cls_FEmTool_Curve.def("GetPolynom", (void (FEmTool_Curve::*)(TColStd_Array1OfReal &)) &FEmTool_Curve::GetPolynom, "returns coefficients of all elements in canonical base.", py::arg("Coeffs"));
cls_FEmTool_Curve.def("NbElements", (Standard_Integer (FEmTool_Curve::*)() const) &FEmTool_Curve::NbElements, "None");
cls_FEmTool_Curve.def("Dimension", (Standard_Integer (FEmTool_Curve::*)() const) &FEmTool_Curve::Dimension, "None");
cls_FEmTool_Curve.def("Base", (opencascade::handle<PLib_Base> (FEmTool_Curve::*)() const) &FEmTool_Curve::Base, "None");
cls_FEmTool_Curve.def("Degree", (Standard_Integer (FEmTool_Curve::*)(const Standard_Integer) const) &FEmTool_Curve::Degree, "None", py::arg("IndexOfElement"));
cls_FEmTool_Curve.def("SetDegree", (void (FEmTool_Curve::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_Curve::SetDegree, "None", py::arg("IndexOfElement"), py::arg("Degree"));
cls_FEmTool_Curve.def("ReduceDegree", [](FEmTool_Curve &self, const Standard_Integer IndexOfElement, const Standard_Real Tol, Standard_Integer & NewDegree, Standard_Real & MaxError){ self.ReduceDegree(IndexOfElement, Tol, NewDegree, MaxError); return std::tuple<Standard_Integer &, Standard_Real &>(NewDegree, MaxError); }, "None", py::arg("IndexOfElement"), py::arg("Tol"), py::arg("NewDegree"), py::arg("MaxError"));
cls_FEmTool_Curve.def_static("get_type_name_", (const char * (*)()) &FEmTool_Curve::get_type_name, "None");
cls_FEmTool_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_Curve::get_type_descriptor, "None");
cls_FEmTool_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_Curve::*)() const) &FEmTool_Curve::DynamicType, "None");

// CLASS: FEMTOOL_ELEMENTARYCRITERION
py::class_<FEmTool_ElementaryCriterion, opencascade::handle<FEmTool_ElementaryCriterion>, Standard_Transient> cls_FEmTool_ElementaryCriterion(mod, "FEmTool_ElementaryCriterion", "defined J Criteria to used in minimisation");

// Methods
cls_FEmTool_ElementaryCriterion.def("Set", (void (FEmTool_ElementaryCriterion::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &FEmTool_ElementaryCriterion::Set, "Set the coefficient of the Element (the Curve)", py::arg("Coeff"));
cls_FEmTool_ElementaryCriterion.def("Set", (void (FEmTool_ElementaryCriterion::*)(const Standard_Real, const Standard_Real)) &FEmTool_ElementaryCriterion::Set, "Set the definition interval of the Element", py::arg("FirstKnot"), py::arg("LastKnot"));
cls_FEmTool_ElementaryCriterion.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_ElementaryCriterion::*)() const) &FEmTool_ElementaryCriterion::DependenceTable, "To know if two dimension are independent.");
cls_FEmTool_ElementaryCriterion.def("Value", (Standard_Real (FEmTool_ElementaryCriterion::*)()) &FEmTool_ElementaryCriterion::Value, "To Compute J(E) where E is the current Element");
cls_FEmTool_ElementaryCriterion.def("Hessian", (void (FEmTool_ElementaryCriterion::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_ElementaryCriterion::Hessian, "To Compute J(E) the coefficients of Hessian matrix of J(E) wich are crossed derivatives in dimensions <Dim1> and <Dim2>. If DependenceTable(Dimension1,Dimension2) is False", py::arg("Dim1"), py::arg("Dim2"), py::arg("H"));
cls_FEmTool_ElementaryCriterion.def("Gradient", (void (FEmTool_ElementaryCriterion::*)(const Standard_Integer, math_Vector &)) &FEmTool_ElementaryCriterion::Gradient, "To Compute the coefficients in the dimension <dim> of the J(E)'s Gradient where E is the current Element", py::arg("Dim"), py::arg("G"));
cls_FEmTool_ElementaryCriterion.def_static("get_type_name_", (const char * (*)()) &FEmTool_ElementaryCriterion::get_type_name, "None");
cls_FEmTool_ElementaryCriterion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_ElementaryCriterion::get_type_descriptor, "None");
cls_FEmTool_ElementaryCriterion.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_ElementaryCriterion::*)() const) &FEmTool_ElementaryCriterion::DynamicType, "None");

// CLASS: FEMTOOL_ELEMENTSOFREFMATRIX
py::class_<FEmTool_ElementsOfRefMatrix, math_FunctionSet> cls_FEmTool_ElementsOfRefMatrix(mod, "FEmTool_ElementsOfRefMatrix", "this class describes the functions needed for calculating matrix elements of RefMatrix for linear criteriums (Tension, Flexsion and Jerk) by Gauss integration. Each function from set gives value Pi(u)'*Pj(u)' or Pi(u)''*Pj(u)'' or Pi(u)'''*Pj(u)''' for each i and j, where Pi(u) is i-th basis function of expansion and (') means derivative.");

// Constructors
cls_FEmTool_ElementsOfRefMatrix.def(py::init<const opencascade::handle<PLib_Base> &, const Standard_Integer>(), py::arg("TheBase"), py::arg("DerOrder"));

// Methods
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator new_", (void * (*)(size_t)) &FEmTool_ElementsOfRefMatrix::operator new, "None", py::arg("theSize"));
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator delete_", (void (*)(void *)) &FEmTool_ElementsOfRefMatrix::operator delete, "None", py::arg("theAddress"));
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator new[]_", (void * (*)(size_t)) &FEmTool_ElementsOfRefMatrix::operator new[], "None", py::arg("theSize"));
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator delete[]_", (void (*)(void *)) &FEmTool_ElementsOfRefMatrix::operator delete[], "None", py::arg("theAddress"));
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator new_", (void * (*)(size_t, void *)) &FEmTool_ElementsOfRefMatrix::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator delete_", (void (*)(void *, void *)) &FEmTool_ElementsOfRefMatrix::operator delete, "None", py::arg(""), py::arg(""));
cls_FEmTool_ElementsOfRefMatrix.def("NbVariables", (Standard_Integer (FEmTool_ElementsOfRefMatrix::*)() const) &FEmTool_ElementsOfRefMatrix::NbVariables, "returns the number of variables of the function. It is supposed that NbVariables = 1.");
cls_FEmTool_ElementsOfRefMatrix.def("NbEquations", (Standard_Integer (FEmTool_ElementsOfRefMatrix::*)() const) &FEmTool_ElementsOfRefMatrix::NbEquations, "returns the number of equations of the function.");
cls_FEmTool_ElementsOfRefMatrix.def("Value", (Standard_Boolean (FEmTool_ElementsOfRefMatrix::*)(const math_Vector &, math_Vector &)) &FEmTool_ElementsOfRefMatrix::Value, "computes the values <F> of the functions for the variable <X>. returns True if the computation was done successfully, False otherwise. F contains results only for i<=j in following order: P0*P0, P0*P1, P0*P2... P1*P1, P1*P2,... (upper triangle of matrix {PiPj})", py::arg("X"), py::arg("F"));

// CLASS: FEMTOOL_LINEARFLEXION
py::class_<FEmTool_LinearFlexion, opencascade::handle<FEmTool_LinearFlexion>, FEmTool_ElementaryCriterion> cls_FEmTool_LinearFlexion(mod, "FEmTool_LinearFlexion", "Criterium of LinearFlexion To Hermit-Jacobi elements");

// Constructors
cls_FEmTool_LinearFlexion.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));

// Methods
cls_FEmTool_LinearFlexion.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_LinearFlexion::*)() const) &FEmTool_LinearFlexion::DependenceTable, "None");
cls_FEmTool_LinearFlexion.def("Value", (Standard_Real (FEmTool_LinearFlexion::*)()) &FEmTool_LinearFlexion::Value, "None");
cls_FEmTool_LinearFlexion.def("Hessian", (void (FEmTool_LinearFlexion::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_LinearFlexion::Hessian, "None", py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
cls_FEmTool_LinearFlexion.def("Gradient", (void (FEmTool_LinearFlexion::*)(const Standard_Integer, math_Vector &)) &FEmTool_LinearFlexion::Gradient, "None", py::arg("Dimension"), py::arg("G"));
cls_FEmTool_LinearFlexion.def_static("get_type_name_", (const char * (*)()) &FEmTool_LinearFlexion::get_type_name, "None");
cls_FEmTool_LinearFlexion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_LinearFlexion::get_type_descriptor, "None");
cls_FEmTool_LinearFlexion.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_LinearFlexion::*)() const) &FEmTool_LinearFlexion::DynamicType, "None");

// CLASS: FEMTOOL_LINEARJERK
py::class_<FEmTool_LinearJerk, opencascade::handle<FEmTool_LinearJerk>, FEmTool_ElementaryCriterion> cls_FEmTool_LinearJerk(mod, "FEmTool_LinearJerk", "Criterion of LinearJerk To Hermit-Jacobi elements");

// Constructors
cls_FEmTool_LinearJerk.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));

// Methods
cls_FEmTool_LinearJerk.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_LinearJerk::*)() const) &FEmTool_LinearJerk::DependenceTable, "None");
cls_FEmTool_LinearJerk.def("Value", (Standard_Real (FEmTool_LinearJerk::*)()) &FEmTool_LinearJerk::Value, "None");
cls_FEmTool_LinearJerk.def("Hessian", (void (FEmTool_LinearJerk::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_LinearJerk::Hessian, "None", py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
cls_FEmTool_LinearJerk.def("Gradient", (void (FEmTool_LinearJerk::*)(const Standard_Integer, math_Vector &)) &FEmTool_LinearJerk::Gradient, "None", py::arg("Dimension"), py::arg("G"));
cls_FEmTool_LinearJerk.def_static("get_type_name_", (const char * (*)()) &FEmTool_LinearJerk::get_type_name, "None");
cls_FEmTool_LinearJerk.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_LinearJerk::get_type_descriptor, "None");
cls_FEmTool_LinearJerk.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_LinearJerk::*)() const) &FEmTool_LinearJerk::DynamicType, "None");

// CLASS: FEMTOOL_LINEARTENSION
py::class_<FEmTool_LinearTension, opencascade::handle<FEmTool_LinearTension>, FEmTool_ElementaryCriterion> cls_FEmTool_LinearTension(mod, "FEmTool_LinearTension", "Criterium of LinearTension To Hermit-Jacobi elements");

// Constructors
cls_FEmTool_LinearTension.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));

// Methods
cls_FEmTool_LinearTension.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_LinearTension::*)() const) &FEmTool_LinearTension::DependenceTable, "None");
cls_FEmTool_LinearTension.def("Value", (Standard_Real (FEmTool_LinearTension::*)()) &FEmTool_LinearTension::Value, "None");
cls_FEmTool_LinearTension.def("Hessian", (void (FEmTool_LinearTension::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_LinearTension::Hessian, "None", py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
cls_FEmTool_LinearTension.def("Gradient", (void (FEmTool_LinearTension::*)(const Standard_Integer, math_Vector &)) &FEmTool_LinearTension::Gradient, "None", py::arg("Dimension"), py::arg("G"));
cls_FEmTool_LinearTension.def_static("get_type_name_", (const char * (*)()) &FEmTool_LinearTension::get_type_name, "None");
cls_FEmTool_LinearTension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_LinearTension::get_type_descriptor, "None");
cls_FEmTool_LinearTension.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_LinearTension::*)() const) &FEmTool_LinearTension::DynamicType, "None");

// CLASS: FEMTOOL_SPARSEMATRIX
py::class_<FEmTool_SparseMatrix, opencascade::handle<FEmTool_SparseMatrix>, Standard_Transient> cls_FEmTool_SparseMatrix(mod, "FEmTool_SparseMatrix", "Sparse Matrix definition");

// Methods
cls_FEmTool_SparseMatrix.def("Init", (void (FEmTool_SparseMatrix::*)(const Standard_Real)) &FEmTool_SparseMatrix::Init, "None", py::arg("Value"));
cls_FEmTool_SparseMatrix.def("ChangeValue", (Standard_Real & (FEmTool_SparseMatrix::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_SparseMatrix::ChangeValue, "None", py::arg("I"), py::arg("J"));
cls_FEmTool_SparseMatrix.def("Decompose", (Standard_Boolean (FEmTool_SparseMatrix::*)()) &FEmTool_SparseMatrix::Decompose, "To make a Factorization of <me>");
cls_FEmTool_SparseMatrix.def("Solve", (void (FEmTool_SparseMatrix::*)(const math_Vector &, math_Vector &) const) &FEmTool_SparseMatrix::Solve, "Direct Solve of AX = B", py::arg("B"), py::arg("X"));
cls_FEmTool_SparseMatrix.def("Prepare", (Standard_Boolean (FEmTool_SparseMatrix::*)()) &FEmTool_SparseMatrix::Prepare, "Make Preparation to iterative solve");
cls_FEmTool_SparseMatrix.def("Solve", [](FEmTool_SparseMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3) -> void { return self.Solve(a0, a1, a2, a3); });
cls_FEmTool_SparseMatrix.def("Solve", [](FEmTool_SparseMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3, const Standard_Real a4) -> void { return self.Solve(a0, a1, a2, a3, a4); });
cls_FEmTool_SparseMatrix.def("Solve", (void (FEmTool_SparseMatrix::*)(const math_Vector &, const math_Vector &, math_Vector &, math_Vector &, const Standard_Real, const Standard_Integer) const) &FEmTool_SparseMatrix::Solve, "Iterative solve of AX = B", py::arg("B"), py::arg("Init"), py::arg("X"), py::arg("Residual"), py::arg("Tolerance"), py::arg("NbIterations"));
cls_FEmTool_SparseMatrix.def("Multiplied", (void (FEmTool_SparseMatrix::*)(const math_Vector &, math_Vector &) const) &FEmTool_SparseMatrix::Multiplied, "returns the product of a SparseMatrix by a vector. An exception is raised if the dimensions are different", py::arg("X"), py::arg("MX"));
cls_FEmTool_SparseMatrix.def("RowNumber", (Standard_Integer (FEmTool_SparseMatrix::*)() const) &FEmTool_SparseMatrix::RowNumber, "returns the row range of a matrix.");
cls_FEmTool_SparseMatrix.def("ColNumber", (Standard_Integer (FEmTool_SparseMatrix::*)() const) &FEmTool_SparseMatrix::ColNumber, "returns the column range of the matrix.");
cls_FEmTool_SparseMatrix.def_static("get_type_name_", (const char * (*)()) &FEmTool_SparseMatrix::get_type_name, "None");
cls_FEmTool_SparseMatrix.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_SparseMatrix::get_type_descriptor, "None");
cls_FEmTool_SparseMatrix.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_SparseMatrix::*)() const) &FEmTool_SparseMatrix::DynamicType, "None");

// CLASS: FEMTOOL_PROFILEMATRIX
py::class_<FEmTool_ProfileMatrix, opencascade::handle<FEmTool_ProfileMatrix>, FEmTool_SparseMatrix> cls_FEmTool_ProfileMatrix(mod, "FEmTool_ProfileMatrix", "Symmetric Sparse ProfileMatrix useful for 1D Finite Element methods");

// Constructors
cls_FEmTool_ProfileMatrix.def(py::init<const TColStd_Array1OfInteger &>(), py::arg("FirstIndexes"));

// Methods
cls_FEmTool_ProfileMatrix.def("Init", (void (FEmTool_ProfileMatrix::*)(const Standard_Real)) &FEmTool_ProfileMatrix::Init, "None", py::arg("Value"));
cls_FEmTool_ProfileMatrix.def("ChangeValue", (Standard_Real & (FEmTool_ProfileMatrix::*)(const Standard_Integer, const Standard_Integer)) &FEmTool_ProfileMatrix::ChangeValue, "None", py::arg("I"), py::arg("J"));
cls_FEmTool_ProfileMatrix.def("Decompose", (Standard_Boolean (FEmTool_ProfileMatrix::*)()) &FEmTool_ProfileMatrix::Decompose, "To make a Factorization of <me>");
cls_FEmTool_ProfileMatrix.def("Solve", (void (FEmTool_ProfileMatrix::*)(const math_Vector &, math_Vector &) const) &FEmTool_ProfileMatrix::Solve, "Direct Solve of AX = B", py::arg("B"), py::arg("X"));
cls_FEmTool_ProfileMatrix.def("Prepare", (Standard_Boolean (FEmTool_ProfileMatrix::*)()) &FEmTool_ProfileMatrix::Prepare, "Make Preparation to iterative solve");
cls_FEmTool_ProfileMatrix.def("Solve", [](FEmTool_ProfileMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3) -> void { return self.Solve(a0, a1, a2, a3); });
cls_FEmTool_ProfileMatrix.def("Solve", [](FEmTool_ProfileMatrix &self, const math_Vector & a0, const math_Vector & a1, math_Vector & a2, math_Vector & a3, const Standard_Real a4) -> void { return self.Solve(a0, a1, a2, a3, a4); });
cls_FEmTool_ProfileMatrix.def("Solve", (void (FEmTool_ProfileMatrix::*)(const math_Vector &, const math_Vector &, math_Vector &, math_Vector &, const Standard_Real, const Standard_Integer) const) &FEmTool_ProfileMatrix::Solve, "Iterative solve of AX = B", py::arg("B"), py::arg("Init"), py::arg("X"), py::arg("Residual"), py::arg("Tolerance"), py::arg("NbIterations"));
cls_FEmTool_ProfileMatrix.def("Multiplied", (void (FEmTool_ProfileMatrix::*)(const math_Vector &, math_Vector &) const) &FEmTool_ProfileMatrix::Multiplied, "returns the product of a SparseMatrix by a vector. An exception is raised if the dimensions are different", py::arg("X"), py::arg("MX"));
cls_FEmTool_ProfileMatrix.def("RowNumber", (Standard_Integer (FEmTool_ProfileMatrix::*)() const) &FEmTool_ProfileMatrix::RowNumber, "returns the row range of a matrix.");
cls_FEmTool_ProfileMatrix.def("ColNumber", (Standard_Integer (FEmTool_ProfileMatrix::*)() const) &FEmTool_ProfileMatrix::ColNumber, "returns the column range of the matrix.");
cls_FEmTool_ProfileMatrix.def("IsInProfile", (Standard_Boolean (FEmTool_ProfileMatrix::*)(const Standard_Integer, const Standard_Integer) const) &FEmTool_ProfileMatrix::IsInProfile, "None", py::arg("i"), py::arg("j"));
cls_FEmTool_ProfileMatrix.def("OutM", (void (FEmTool_ProfileMatrix::*)() const) &FEmTool_ProfileMatrix::OutM, "None");
cls_FEmTool_ProfileMatrix.def("OutS", (void (FEmTool_ProfileMatrix::*)() const) &FEmTool_ProfileMatrix::OutS, "None");
cls_FEmTool_ProfileMatrix.def_static("get_type_name_", (const char * (*)()) &FEmTool_ProfileMatrix::get_type_name, "None");
cls_FEmTool_ProfileMatrix.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_ProfileMatrix::get_type_descriptor, "None");
cls_FEmTool_ProfileMatrix.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_ProfileMatrix::*)() const) &FEmTool_ProfileMatrix::DynamicType, "None");


}
