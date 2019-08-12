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
#include <Geom2dGcc_QCurve.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <GccEnt_QualifiedLin.hxx>
#include <gp_Pnt2d.hxx>
#include <GccEnt_Position.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dGcc_Circ2dTanOnRadGeo.hxx>

void bind_Geom2dGcc_Circ2dTanOnRadGeo(py::module &mod){

py::class_<Geom2dGcc_Circ2dTanOnRadGeo, std::unique_ptr<Geom2dGcc_Circ2dTanOnRadGeo, Deleter<Geom2dGcc_Circ2dTanOnRadGeo>>> cls_Geom2dGcc_Circ2dTanOnRadGeo(mod, "Geom2dGcc_Circ2dTanOnRadGeo", "This class implements the algorithms used to create a 2d circle tangent to a 2d entity, centered on a 2d entity and with a given radius. More than one argument must be a curve. The arguments of all construction methods are : - The qualified element for the tangency constrains (QualifiedCirc, QualifiedLin, QualifiedCurvPoints). - The Center element (circle, line, curve). - A real Tolerance. Tolerance is only used in the limits cases. For example : We want to create a circle tangent to an OutsideCurv Cu1 centered on a line OnLine with a radius Radius and with a tolerance Tolerance. If we did not use Tolerance it is impossible to find a solution in the following case : OnLine is outside Cu1. There is no intersection point between Cu1 and OnLine. The distance between the line and the circle is greater than Radius. With Tolerance we will give a solution if the distance between Cu1 and OnLine is lower than or equal Tolerance.");

// Constructors
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnLine"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const Geom2dGcc_QCurve &, const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCirc"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const GccEnt_QualifiedLin &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const Geom2dGcc_QCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Point1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanOnRadGeo::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2dTanOnRadGeo::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanOnRadGeo::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2dTanOnRadGeo::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2dTanOnRadGeo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2dTanOnRadGeo::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2dTanOnRadGeo::*)() const) &Geom2dGcc_Circ2dTanOnRadGeo::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2dTanOnRadGeo::*)() const) &Geom2dGcc_Circ2dTanOnRadGeo::NbSolutions, "This method returns the number of solutions. It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2dTanOnRadGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanOnRadGeo::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be careful: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("WhichQualifier", (void (Geom2dGcc_Circ2dTanOnRadGeo::*)(const Standard_Integer, GccEnt_Position &) const) &Geom2dGcc_Circ2dTanOnRadGeo::WhichQualifier, "None", py::arg("Index"), py::arg("Qualif1"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("Tangency1", [](Geom2dGcc_Circ2dTanOnRadGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the tangency point on the solution curv. PntArg is the tangency point on the argument curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("CenterOn3", [](Geom2dGcc_Circ2dTanOnRadGeo &self, const Standard_Integer Index, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(Index, ParArg, PntSol); return ParArg; }, "Returns informations about the center (on the curv) of the result. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the center point of the solution curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2dTanOnRadGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanOnRadGeo::IsTheSame1, "Returns True if the solution number Index is equal to the first argument and False in the other cases. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));

// Enums

}