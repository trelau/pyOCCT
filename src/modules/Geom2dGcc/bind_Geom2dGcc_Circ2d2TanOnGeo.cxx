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
#include <Geom2dAdaptor_Curve.hxx>
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
#include <Geom2dGcc_Circ2d2TanOnGeo.hxx>

void bind_Geom2dGcc_Circ2d2TanOnGeo(py::module &mod){

py::class_<Geom2dGcc_Circ2d2TanOnGeo, std::unique_ptr<Geom2dGcc_Circ2d2TanOnGeo, Deleter<Geom2dGcc_Circ2d2TanOnGeo>>> cls_Geom2dGcc_Circ2d2TanOnGeo(mod, "Geom2dGcc_Circ2d2TanOnGeo", "This class implements the algorithms used to create 2d circles TANgent to 2 entities and having the center ON a curve. The order of the tangency argument is always QualifiedCirc, QualifiedLin, QualifiedCurv, Pnt2d. the arguments are : - The two tangency arguments (lines, circles or points). - The center line (a curve). - The parameter for each tangency argument which is a curve. - The tolerance.");

// Constructors
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurv"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedLin &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurv"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const GccEnt_QualifiedCirc &, const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnCurv"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurv"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const GccEnt_QualifiedLin &, const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurv"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("OnCurv"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOnGeo::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOnGeo::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOnGeo::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOnGeo::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d2TanOnGeo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d2TanOnGeo::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnGeo::*)() const) &Geom2dGcc_Circ2d2TanOnGeo::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_Geom2dGcc_Circ2d2TanOnGeo.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2d2TanOnGeo::*)() const) &Geom2dGcc_Circ2d2TanOnGeo::NbSolutions, "This method returns the number of solutions. It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d2TanOnGeo.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d2TanOnGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOnGeo::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be careful: the Index is only a way to get all the solutions, but is not associated to those outside the context of the algorithm-object. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("WhichQualifier", (void (Geom2dGcc_Circ2d2TanOnGeo::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d2TanOnGeo::WhichQualifier, "It returns the informations about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computedin case of unqualified).", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("Tangency1", [](Geom2dGcc_Circ2d2TanOnGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the tangency point on the solution curv. PntArg is the tangency point on the argument curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("Tangency2", [](Geom2dGcc_Circ2d2TanOnGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the second argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the tangency point on the solution curv. PntArg is the tangency point on the argument curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("CenterOn3", [](Geom2dGcc_Circ2d2TanOnGeo &self, const Standard_Integer Index, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(Index, ParArg, PntSol); return ParArg; }, "Returns informations about the center (on the curv) of the result. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the center point of the solution curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOnGeo::IsTheSame1, "Returns True if the solution number Index is equal to the first argument and False in the other cases. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOnGeo::IsTheSame2, "Returns True if the solution number Index is equal to the second argument and False in the other cases. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));

// Enums

}