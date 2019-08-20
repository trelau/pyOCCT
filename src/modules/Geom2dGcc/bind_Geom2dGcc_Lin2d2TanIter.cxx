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
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <gp_Lin2d.hxx>
#include <GccEnt_Position.hxx>
#include <Geom2dGcc_Lin2d2TanIter.hxx>

void bind_Geom2dGcc_Lin2d2TanIter(py::module &mod){

py::class_<Geom2dGcc_Lin2d2TanIter, std::unique_ptr<Geom2dGcc_Lin2d2TanIter>> cls_Geom2dGcc_Lin2d2TanIter(mod, "Geom2dGcc_Lin2d2TanIter", "This class implements the algorithms used to create 2d lines tangent to 2 other elements which can be circles, curves or points. More than one argument must be a curve.");

// Constructors
cls_Geom2dGcc_Lin2d2TanIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("ThePoint"), py::arg("Param1"), py::arg("Tolang"));
cls_Geom2dGcc_Lin2d2TanIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Param2"), py::arg("Tolang"));
cls_Geom2dGcc_Lin2d2TanIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolang"));

// Fields

// Methods
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Lin2d2TanIter::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Lin2d2TanIter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Lin2d2TanIter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Lin2d2TanIter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Lin2d2TanIter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Lin2d2TanIter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Lin2d2TanIter.def("IsDone", (Standard_Boolean (Geom2dGcc_Lin2d2TanIter::*)() const) &Geom2dGcc_Lin2d2TanIter::IsDone, "This methode returns true when there is a solution and false in the other cases.");
cls_Geom2dGcc_Lin2d2TanIter.def("ThisSolution", (gp_Lin2d (Geom2dGcc_Lin2d2TanIter::*)() const) &Geom2dGcc_Lin2d2TanIter::ThisSolution, "Returns the solution.");
cls_Geom2dGcc_Lin2d2TanIter.def("WhichQualifier", (void (Geom2dGcc_Lin2d2TanIter::*)(GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Lin2d2TanIter::WhichQualifier, "None", py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Lin2d2TanIter.def("Tangency1", [](Geom2dGcc_Lin2d2TanIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Lin2d2TanIter.def("Tangency2", [](Geom2dGcc_Lin2d2TanIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "None", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));

// Enums

}