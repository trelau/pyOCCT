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
#include <Geom2dGcc_QCurve.hxx>
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
#include <Geom2dGcc_Circ2d2TanRadGeo.hxx>

void bind_Geom2dGcc_Circ2d2TanRadGeo(py::module &mod){

py::class_<Geom2dGcc_Circ2d2TanRadGeo, std::unique_ptr<Geom2dGcc_Circ2d2TanRadGeo>> cls_Geom2dGcc_Circ2d2TanRadGeo(mod, "Geom2dGcc_Circ2d2TanRadGeo", "This class implements the algorithms used to create 2d circles tangent to one curve and a point/line/circle/curv and with a given radius. For each construction methods arguments are: - Two Qualified elements for tangency constrains. (for example EnclosedCirc if we want the solution inside the argument EnclosedCirc). - Two Reals. One (Radius) for the radius and the other (Tolerance) for the tolerance. Tolerance is only used for the limit cases. For example : We want to create a circle inside a circle C1 and inside a curve Cu2 with a radius Radius and a tolerance Tolerance. If we did not used Tolerance it is impossible to find a solution in the following case : Cu2 is inside C1 and there is no intersection point between the two elements. With Tolerance we will get a solution if the lowest distance between C1 and Cu2 is lower than or equal Tolerance.");

// Constructors
cls_Geom2dGcc_Circ2d2TanRadGeo.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("Radius"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanRadGeo::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanRadGeo::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanRadGeo::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanRadGeo::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d2TanRadGeo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d2TanRadGeo::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d2TanRadGeo::*)() const) &Geom2dGcc_Circ2d2TanRadGeo::IsDone, "This method returns True if the algorithm succeeded.");
cls_Geom2dGcc_Circ2d2TanRadGeo.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2d2TanRadGeo::*)() const) &Geom2dGcc_Circ2d2TanRadGeo::NbSolutions, "This method returns the number of solutions. It raises NotDone if the algorithm failed.");
cls_Geom2dGcc_Circ2d2TanRadGeo.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d2TanRadGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRadGeo::ThisSolution, "Returns the solution number Index. Be careful: the Index is only a way to get all the solutions, but is not associated to those outside the context of the algorithm-object. It raises OutOfRange exception if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("WhichQualifier", (void (Geom2dGcc_Circ2d2TanRadGeo::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d2TanRadGeo::WhichQualifier, "It returns the information about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computedin case of unqualified).", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("Tangency1", [](Geom2dGcc_Circ2d2TanRadGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns information about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution. ParArg is the intrinsic parameter of the point PntSol on the first argument. It raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("Tangency2", [](Geom2dGcc_Circ2d2TanRadGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns information about the tangency point between the result number Index and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution. ParArg is the intrinsic parameter of the point PntArg on the second argument. It raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d2TanRadGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRadGeo::IsTheSame1, "Returns True if the solution number Index is equal to the first argument. It raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d2TanRadGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRadGeo::IsTheSame2, "Returns True if the solution number Index is equal to the second argument. It raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"));

// Enums

}