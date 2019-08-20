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
#include <GccEnt_Position.hxx>
#include <gp_Pnt2d.hxx>
#include <Geom2dGcc_Lin2dTanOblIter.hxx>

void bind_Geom2dGcc_Lin2dTanOblIter(py::module &mod){

py::class_<Geom2dGcc_Lin2dTanOblIter, std::unique_ptr<Geom2dGcc_Lin2dTanOblIter>> cls_Geom2dGcc_Lin2dTanOblIter(mod, "Geom2dGcc_Lin2dTanOblIter", "This class implements the algorithms used to create 2d line tangent to a curve QualifiedCurv and doing an angle Angle with a line TheLin. The angle must be in Radian.");

// Constructors
cls_Geom2dGcc_Lin2dTanOblIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("TheLin"), py::arg("Param1"), py::arg("TolAng"));
cls_Geom2dGcc_Lin2dTanOblIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("TheLin"), py::arg("Param1"), py::arg("TolAng"), py::arg("Angle"));

// Fields

// Methods
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Lin2dTanOblIter::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Lin2dTanOblIter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Lin2dTanOblIter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Lin2dTanOblIter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Lin2dTanOblIter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Lin2dTanOblIter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Lin2dTanOblIter.def("IsDone", (Standard_Boolean (Geom2dGcc_Lin2dTanOblIter::*)() const) &Geom2dGcc_Lin2dTanOblIter::IsDone, "This method returns true when there is a solution and false in the other cases.");
cls_Geom2dGcc_Lin2dTanOblIter.def("ThisSolution", (gp_Lin2d (Geom2dGcc_Lin2dTanOblIter::*)() const) &Geom2dGcc_Lin2dTanOblIter::ThisSolution, "None");
cls_Geom2dGcc_Lin2dTanOblIter.def("WhichQualifier", (void (Geom2dGcc_Lin2dTanOblIter::*)(GccEnt_Position &) const) &Geom2dGcc_Lin2dTanOblIter::WhichQualifier, "None", py::arg("Qualif1"));
cls_Geom2dGcc_Lin2dTanOblIter.def("Tangency1", [](Geom2dGcc_Lin2dTanOblIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "None", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Lin2dTanOblIter.def("Intersection2", [](Geom2dGcc_Lin2dTanOblIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Intersection2(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "None", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Lin2dTanOblIter.def("IsParallel2", (Standard_Boolean (Geom2dGcc_Lin2dTanOblIter::*)() const) &Geom2dGcc_Lin2dTanOblIter::IsParallel2, "None");

// Enums

}