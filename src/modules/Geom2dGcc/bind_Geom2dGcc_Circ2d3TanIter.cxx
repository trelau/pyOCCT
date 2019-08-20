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
#include <Geom2dGcc_Circ2d3TanIter.hxx>

void bind_Geom2dGcc_Circ2d3TanIter(py::module &mod){

py::class_<Geom2dGcc_Circ2d3TanIter, std::unique_ptr<Geom2dGcc_Circ2d3TanIter>> cls_Geom2dGcc_Circ2d3TanIter(mod, "Geom2dGcc_Circ2d3TanIter", "This class implements the algorithms used to create 2d circles tangent to 3 points/lines/circles/ curves with one curve or more. The arguments of all construction methods are : - The three qualifiied elements for the tangency constrains (QualifiedCirc, QualifiedLine, Qualifiedcurv, Points). - A parameter for each QualifiedCurv.");

// Constructors
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point3"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point3"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point1"), py::arg("Point2"), py::arg("Param1"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point2"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d3TanIter::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d3TanIter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d3TanIter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d3TanIter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d3TanIter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d3TanIter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d3TanIter.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d3TanIter::*)() const) &Geom2dGcc_Circ2d3TanIter::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_Geom2dGcc_Circ2d3TanIter.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d3TanIter::*)() const) &Geom2dGcc_Circ2d3TanIter::ThisSolution, "Returns the solution. It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d3TanIter.def("WhichQualifier", (void (Geom2dGcc_Circ2d3TanIter::*)(GccEnt_Position &, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d3TanIter::WhichQualifier, "None", py::arg("Qualif1"), py::arg("Qualif2"), py::arg("Qualif3"));
cls_Geom2dGcc_Circ2d3TanIter.def("Tangency1", [](Geom2dGcc_Circ2d3TanIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3TanIter.def("Tangency2", [](Geom2dGcc_Circ2d3TanIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3TanIter.def("Tangency3", [](Geom2dGcc_Circ2d3TanIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency3(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the third argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3TanIter.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d3TanIter::*)() const) &Geom2dGcc_Circ2d3TanIter::IsTheSame1, "It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d3TanIter.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d3TanIter::*)() const) &Geom2dGcc_Circ2d3TanIter::IsTheSame2, "It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d3TanIter.def("IsTheSame3", (Standard_Boolean (Geom2dGcc_Circ2d3TanIter::*)() const) &Geom2dGcc_Circ2d3TanIter::IsTheSame3, "It raises NotDone if the construction algorithm didn't succeed.");

// Enums

}