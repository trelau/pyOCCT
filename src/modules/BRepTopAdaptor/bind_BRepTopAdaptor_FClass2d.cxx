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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepTopAdaptor_FClass2d.hxx>
#include <BRepTopAdaptor_SeqOfPtr.hxx>
#include <TColStd_SequenceOfInteger.hxx>

void bind_BRepTopAdaptor_FClass2d(py::module &mod){

py::class_<BRepTopAdaptor_FClass2d, std::unique_ptr<BRepTopAdaptor_FClass2d>> cls_BRepTopAdaptor_FClass2d(mod, "BRepTopAdaptor_FClass2d", "None");

// Constructors
cls_BRepTopAdaptor_FClass2d.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("F"), py::arg("Tol"));

// Fields

// Methods
// cls_BRepTopAdaptor_FClass2d.def_static("operator new_", (void * (*)(size_t)) &BRepTopAdaptor_FClass2d::operator new, "None", py::arg("theSize"));
// cls_BRepTopAdaptor_FClass2d.def_static("operator delete_", (void (*)(void *)) &BRepTopAdaptor_FClass2d::operator delete, "None", py::arg("theAddress"));
// cls_BRepTopAdaptor_FClass2d.def_static("operator new[]_", (void * (*)(size_t)) &BRepTopAdaptor_FClass2d::operator new[], "None", py::arg("theSize"));
// cls_BRepTopAdaptor_FClass2d.def_static("operator delete[]_", (void (*)(void *)) &BRepTopAdaptor_FClass2d::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTopAdaptor_FClass2d.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTopAdaptor_FClass2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTopAdaptor_FClass2d.def_static("operator delete_", (void (*)(void *, void *)) &BRepTopAdaptor_FClass2d::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTopAdaptor_FClass2d.def("PerformInfinitePoint", (TopAbs_State (BRepTopAdaptor_FClass2d::*)() const) &BRepTopAdaptor_FClass2d::PerformInfinitePoint, "None");
cls_BRepTopAdaptor_FClass2d.def("Perform", [](BRepTopAdaptor_FClass2d &self, const gp_Pnt2d & a0) -> TopAbs_State { return self.Perform(a0); });
cls_BRepTopAdaptor_FClass2d.def("Perform", (TopAbs_State (BRepTopAdaptor_FClass2d::*)(const gp_Pnt2d &, const Standard_Boolean) const) &BRepTopAdaptor_FClass2d::Perform, "None", py::arg("Puv"), py::arg("RecadreOnPeriodic"));
cls_BRepTopAdaptor_FClass2d.def("Destroy", (void (BRepTopAdaptor_FClass2d::*)()) &BRepTopAdaptor_FClass2d::Destroy, "None");
cls_BRepTopAdaptor_FClass2d.def("Copy", (const BRepTopAdaptor_FClass2d & (BRepTopAdaptor_FClass2d::*)(const BRepTopAdaptor_FClass2d &) const) &BRepTopAdaptor_FClass2d::Copy, "None", py::arg("Other"));
// cls_BRepTopAdaptor_FClass2d.def("operator=", (const BRepTopAdaptor_FClass2d & (BRepTopAdaptor_FClass2d::*)(const BRepTopAdaptor_FClass2d &) const) &BRepTopAdaptor_FClass2d::operator=, "None", py::arg("Other"));
cls_BRepTopAdaptor_FClass2d.def("TestOnRestriction", [](BRepTopAdaptor_FClass2d &self, const gp_Pnt2d & a0, const Standard_Real a1) -> TopAbs_State { return self.TestOnRestriction(a0, a1); });
cls_BRepTopAdaptor_FClass2d.def("TestOnRestriction", (TopAbs_State (BRepTopAdaptor_FClass2d::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean) const) &BRepTopAdaptor_FClass2d::TestOnRestriction, "Test a point with +- an offset (Tol) and returns On if some points are OUT an some are IN (Caution: Internal use . see the code for more details)", py::arg("Puv"), py::arg("Tol"), py::arg("RecadreOnPeriodic"));

// Enums

}