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
#include <Standard.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_QualifiedLin.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt_Position.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GccAna_Circ2d2TanOn.hxx>

void bind_GccAna_Circ2d2TanOn(py::module &mod){

py::class_<GccAna_Circ2d2TanOn> cls_GccAna_Circ2d2TanOn(mod, "GccAna_Circ2d2TanOn", "Describes functions for building a 2D circle - tangential to 2 curves, or - tangential to a curve and passing through a point, or - passing through 2 points, and with its center on a curve. For these analytic algorithms, curves are circles or lines. A Circ2d2TanOn object provides a framework for: - defining the construction of 2D circles(s), - implementing the construction algorithm, and - consulting the result(s).");

// Constructors
cls_GccAna_Circ2d2TanOn.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const gp_Lin2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnLine"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedLin &, const gp_Lin2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnLine"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const gp_Lin2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnLine"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const GccEnt_QualifiedCirc &, const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnLine"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const GccEnt_QualifiedLin &, const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnLine"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("OnLine"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const gp_Circ2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCirc"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedLin &, const gp_Circ2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCirc"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const GccEnt_QualifiedCirc &, const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnCirc"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const gp_Circ2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCirc"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const GccEnt_QualifiedLin &, const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnCirc"), py::arg("Tolerance"));
cls_GccAna_Circ2d2TanOn.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("OnCirc"), py::arg("Tolerance"));

// Fields

// Methods
// cls_GccAna_Circ2d2TanOn.def_static("operator new_", (void * (*)(size_t)) &GccAna_Circ2d2TanOn::operator new, "None", py::arg("theSize"));
// cls_GccAna_Circ2d2TanOn.def_static("operator delete_", (void (*)(void *)) &GccAna_Circ2d2TanOn::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Circ2d2TanOn.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Circ2d2TanOn::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Circ2d2TanOn.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Circ2d2TanOn::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Circ2d2TanOn.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Circ2d2TanOn::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Circ2d2TanOn.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Circ2d2TanOn::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Circ2d2TanOn.def("IsDone", (Standard_Boolean (GccAna_Circ2d2TanOn::*)() const) &GccAna_Circ2d2TanOn::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_GccAna_Circ2d2TanOn.def("NbSolutions", (Standard_Integer (GccAna_Circ2d2TanOn::*)() const) &GccAna_Circ2d2TanOn::NbSolutions, "Returns the number of circles, representing solutions computed by this algorithm. Exceptions StdFail_NotDone if the construction fails.");
cls_GccAna_Circ2d2TanOn.def("ThisSolution", (gp_Circ2d (GccAna_Circ2d2TanOn::*)(const Standard_Integer) const) &GccAna_Circ2d2TanOn::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be careful: the Index is only a way to get all the solutions, but is not associated to those outside the context of the algorithm-object. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_GccAna_Circ2d2TanOn.def("WhichQualifier", (void (GccAna_Circ2d2TanOn::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &GccAna_Circ2d2TanOn::WhichQualifier, "Returns the qualifiers Qualif1 and Qualif2 of the tangency arguments for the solution of index Index computed by this algorithm. The returned qualifiers are: - those specified at the start of construction when the solutions are defined as enclosed, enclosing or outside with respect to the arguments, or - those computed during construction (i.e. enclosed, enclosing or outside) when the solutions are defined as unqualified with respect to the arguments, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_GccAna_Circ2d2TanOn.def("Tangency1", [](GccAna_Circ2d2TanOn &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns the informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution ParArg is the intrinsic parameter of the point PntSol on the first argument. Raises OutOfRange if Index is greater than the number of solutions and NotDone if IsDone returns false.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Circ2d2TanOn.def("Tangency2", [](GccAna_Circ2d2TanOn &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns the informations about the tangency point between the result number Index and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution. ParArg is the intrinsic parameter of the point PntSol on the second argument. Raises OutOfRange if Index is greater than the number of solutions and NotDone if IsDone returns false.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Circ2d2TanOn.def("CenterOn3", [](GccAna_Circ2d2TanOn &self, const Standard_Integer Index, Standard_Real & ParArg, gp_Pnt2d & PntArg){ self.CenterOn3(Index, ParArg, PntArg); return ParArg; }, "Returns the informations about the center (on the curv) of the result number Index and the third argument. ParArg is the intrinsic parameter of the point PntArg on the third argument. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParArg"), py::arg("PntArg"));
cls_GccAna_Circ2d2TanOn.def("IsTheSame1", (Standard_Boolean (GccAna_Circ2d2TanOn::*)(const Standard_Integer) const) &GccAna_Circ2d2TanOn::IsTheSame1, "True if the solution and the first argument are the same (2 circles). If R1 is the radius of the first argument and Rsol the radius of the solution and dist the distance between the two centers, we concider the two circles are identical if R1+dist-Rsol is less than Tolerance. False in the other cases. Raises OutOfRange if Index is greater than the number of solutions and NotDone if IsDone returns false.", py::arg("Index"));
cls_GccAna_Circ2d2TanOn.def("IsTheSame2", (Standard_Boolean (GccAna_Circ2d2TanOn::*)(const Standard_Integer) const) &GccAna_Circ2d2TanOn::IsTheSame2, "True if the solution and the second argument are the same (2 circles). If R2 is the radius of the second argument and Rsol the radius of the solution and dist the distance between the two centers, we concider the two circles are identical if R2+dist-Rsol is less than Tolerance. False in the other cases. Raises OutOfRange if Index is greater than the number of solutions and NotDone if IsDone returns false.", py::arg("Index"));

// Enums

}