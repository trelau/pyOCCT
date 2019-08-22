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
#include <GccAna_Circ2dTanOnRad.hxx>

void bind_GccAna_Circ2dTanOnRad(py::module &mod){

py::class_<GccAna_Circ2dTanOnRad> cls_GccAna_Circ2dTanOnRad(mod, "GccAna_Circ2dTanOnRad", "This class implements the algorithms used to create a 2d circle tangent to a 2d entity, centered on a curv and with a given radius. The arguments of all construction methods are : - The qualified element for the tangency constrains (QualifiedCirc, QualifiedLin, Points). - The Center element (circle, line). - A real Tolerance. Tolerance is only used in the limits cases. For example : We want to create a circle tangent to an OutsideCirc C1 centered on a line OnLine with a radius Radius and with a tolerance Tolerance. If we did not use Tolerance it is impossible to find a solution in the the following case : OnLine is outside C1. There is no intersection point between C1 and OnLine. The distance between the line and the circle is greater than Radius. With Tolerance we will give a solution if the distance between C1 and OnLine is lower than or equal Tolerance.");

// Constructors
cls_GccAna_Circ2dTanOnRad.def(py::init<const GccEnt_QualifiedCirc &, const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnLine"), py::arg("Radius"), py::arg("Tolerance"));
cls_GccAna_Circ2dTanOnRad.def(py::init<const GccEnt_QualifiedLin &, const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnLine"), py::arg("Radius"), py::arg("Tolerance"));
cls_GccAna_Circ2dTanOnRad.def(py::init<const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("Point1"), py::arg("OnLine"), py::arg("Radius"), py::arg("Tolerance"));
cls_GccAna_Circ2dTanOnRad.def(py::init<const GccEnt_QualifiedCirc &, const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCirc"), py::arg("Radius"), py::arg("Tolerance"));
cls_GccAna_Circ2dTanOnRad.def(py::init<const GccEnt_QualifiedLin &, const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCirc"), py::arg("Radius"), py::arg("Tolerance"));
cls_GccAna_Circ2dTanOnRad.def(py::init<const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("Point1"), py::arg("OnCirc"), py::arg("Radius"), py::arg("Tolerance"));

// Fields

// Methods
// cls_GccAna_Circ2dTanOnRad.def_static("operator new_", (void * (*)(size_t)) &GccAna_Circ2dTanOnRad::operator new, "None", py::arg("theSize"));
// cls_GccAna_Circ2dTanOnRad.def_static("operator delete_", (void (*)(void *)) &GccAna_Circ2dTanOnRad::operator delete, "None", py::arg("theAddress"));
// cls_GccAna_Circ2dTanOnRad.def_static("operator new[]_", (void * (*)(size_t)) &GccAna_Circ2dTanOnRad::operator new[], "None", py::arg("theSize"));
// cls_GccAna_Circ2dTanOnRad.def_static("operator delete[]_", (void (*)(void *)) &GccAna_Circ2dTanOnRad::operator delete[], "None", py::arg("theAddress"));
// cls_GccAna_Circ2dTanOnRad.def_static("operator new_", (void * (*)(size_t, void *)) &GccAna_Circ2dTanOnRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccAna_Circ2dTanOnRad.def_static("operator delete_", (void (*)(void *, void *)) &GccAna_Circ2dTanOnRad::operator delete, "None", py::arg(""), py::arg(""));
cls_GccAna_Circ2dTanOnRad.def("IsDone", (Standard_Boolean (GccAna_Circ2dTanOnRad::*)() const) &GccAna_Circ2dTanOnRad::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_GccAna_Circ2dTanOnRad.def("NbSolutions", (Standard_Integer (GccAna_Circ2dTanOnRad::*)() const) &GccAna_Circ2dTanOnRad::NbSolutions, "This method returns the number of circles, representing solutions. Raises NotDone if the construction algorithm didn't succeed.");
cls_GccAna_Circ2dTanOnRad.def("ThisSolution", (gp_Circ2d (GccAna_Circ2dTanOnRad::*)(const Standard_Integer) const) &GccAna_Circ2dTanOnRad::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be careful: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions", py::arg("Index"));
cls_GccAna_Circ2dTanOnRad.def("WhichQualifier", (void (GccAna_Circ2dTanOnRad::*)(const Standard_Integer, GccEnt_Position &) const) &GccAna_Circ2dTanOnRad::WhichQualifier, "Returns the qualifier Qualif1 of the tangency argument for the solution of index Index computed by this algorithm. The returned qualifier is: - that specified at the start of construction when the solutions are defined as enclosed, enclosing or outside with respect to the argument, or - that computed during construction (i.e. enclosed, enclosing or outside) when the solutions are defined as unqualified with respect to the argument, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"));
cls_GccAna_Circ2dTanOnRad.def("Tangency1", [](GccAna_Circ2dTanOnRad &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the tangency point on the solution curv. PntArg is the tangency point on the argument curv. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Circ2dTanOnRad.def("CenterOn3", [](GccAna_Circ2dTanOnRad &self, const Standard_Integer Index, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(Index, ParArg, PntSol); return ParArg; }, "Returns informations about the center (on the curv) of the result. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the center point of the solution curv. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParArg"), py::arg("PntSol"));
cls_GccAna_Circ2dTanOnRad.def("IsTheSame1", (Standard_Boolean (GccAna_Circ2dTanOnRad::*)(const Standard_Integer) const) &GccAna_Circ2dTanOnRad::IsTheSame1, "Returns True if the solution number Index is equal to the first argument and False in the other cases. Raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));

// Enums

}