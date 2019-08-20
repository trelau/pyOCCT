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
#include <Geom2dGcc_QualifiedCurve.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Point.hxx>
#include <GccAna_Circ2dTanOnRad.hxx>
#include <Geom2dGcc_Circ2dTanOnRadGeo.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt_Position.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dGcc_Circ2dTanOnRad.hxx>

void bind_Geom2dGcc_Circ2dTanOnRad(py::module &mod){

py::class_<Geom2dGcc_Circ2dTanOnRad, std::unique_ptr<Geom2dGcc_Circ2dTanOnRad>> cls_Geom2dGcc_Circ2dTanOnRad(mod, "Geom2dGcc_Circ2dTanOnRad", "This class implements the algorithms used to create a 2d circle tangent to a 2d entity, centered on a 2d entity and with a given radius. More than one argument must be a curve. The arguments of all construction methods are : - The qualified element for the tangency constrains (QualifiedCirc, QualifiedLin, QualifiedCurvPoints). - The Center element (circle, line, curve). - A real Tolerance. Tolerance is only used in the limits cases. For example : We want to create a circle tangent to an OutsideCurv Cu1 centered on a line OnLine with a radius Radius and with a tolerance Tolerance. If we did not used Tolerance it is impossible to find a solution in the the following case : OnLine is outside Cu1. There is no intersection point between Cu1 and OnLine. The distance between the line and the circle is greater than Radius. With Tolerance we will give a solution if the distance between Cu1 and OnLine is lower than or equal Tolerance.");

// Constructors
cls_Geom2dGcc_Circ2dTanOnRad.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRad.def(py::init<const opencascade::handle<Geom2d_Point> &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Point1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanOnRad::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2dTanOnRad::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanOnRad::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2dTanOnRad::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2dTanOnRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2dTanOnRad::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2dTanOnRad.def("Results", (void (Geom2dGcc_Circ2dTanOnRad::*)(const GccAna_Circ2dTanOnRad &)) &Geom2dGcc_Circ2dTanOnRad::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2dTanOnRad.def("Results", (void (Geom2dGcc_Circ2dTanOnRad::*)(const Geom2dGcc_Circ2dTanOnRadGeo &)) &Geom2dGcc_Circ2dTanOnRad::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2dTanOnRad.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2dTanOnRad::*)() const) &Geom2dGcc_Circ2dTanOnRad::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm which has reached its numeric limits.");
cls_Geom2dGcc_Circ2dTanOnRad.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2dTanOnRad::*)() const) &Geom2dGcc_Circ2dTanOnRad::NbSolutions, "Returns the number of circles, representing solutions computed by this algorithm. Exceptions: StdFail_NotDone if the construction fails.");
cls_Geom2dGcc_Circ2dTanOnRad.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2dTanOnRad::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanOnRad::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Circ2dTanOnRad.def("WhichQualifier", (void (Geom2dGcc_Circ2dTanOnRad::*)(const Standard_Integer, GccEnt_Position &) const) &Geom2dGcc_Circ2dTanOnRad::WhichQualifier, "Returns the qualifier Qualif1 of the tangency argument for the solution of index Index computed by this algorithm. The returned qualifier is: - that specified at the start of construction when the solutions are defined as enclosed, enclosing or outside with respect to the arguments, or - that computed during construction (i.e. enclosed, enclosing or outside) when the solutions are defined as unqualified with respect to the arguments, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"));
cls_Geom2dGcc_Circ2dTanOnRad.def("Tangency1", [](Geom2dGcc_Circ2dTanOnRad &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the tangency point on the solution curv. PntArg is the tangency point on the argument curv. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2dTanOnRad.def("CenterOn3", [](Geom2dGcc_Circ2dTanOnRad &self, const Standard_Integer Index, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(Index, ParArg, PntSol); return ParArg; }, "Returns the center PntSol on the second argument (i.e. line or circle) of the solution of index Index computed by this algorithm. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the center point of the solution curv. PntArg is the projection of PntSol on the argument curv. Exceptions: Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2dTanOnRad.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2dTanOnRad::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanOnRad::IsTheSame1, "Returns true if the solution of index Index and the first argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. OutOfRange is raised if Index is greater than the number of solutions. notDone is raised if the construction algorithm did not succeed.", py::arg("Index"));

// Enums

}