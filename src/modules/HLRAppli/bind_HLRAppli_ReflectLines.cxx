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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRBRep_TypeOfResultingEdge.hxx>
#include <HLRAlgo_Projector.hxx>
#include <Standard_Handle.hxx>
#include <HLRBRep_Algo.hxx>
#include <HLRAppli_ReflectLines.hxx>

void bind_HLRAppli_ReflectLines(py::module &mod){

py::class_<HLRAppli_ReflectLines, std::unique_ptr<HLRAppli_ReflectLines, Deleter<HLRAppli_ReflectLines>>> cls_HLRAppli_ReflectLines(mod, "HLRAppli_ReflectLines", "This class builds reflect lines on a shape according to the axes of view defined by user. Reflect lines are represented by edges in 3d.");

// Constructors
cls_HLRAppli_ReflectLines.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));

// Fields

// Methods
// cls_HLRAppli_ReflectLines.def_static("operator new_", (void * (*)(size_t)) &HLRAppli_ReflectLines::operator new, "None", py::arg("theSize"));
// cls_HLRAppli_ReflectLines.def_static("operator delete_", (void (*)(void *)) &HLRAppli_ReflectLines::operator delete, "None", py::arg("theAddress"));
// cls_HLRAppli_ReflectLines.def_static("operator new[]_", (void * (*)(size_t)) &HLRAppli_ReflectLines::operator new[], "None", py::arg("theSize"));
// cls_HLRAppli_ReflectLines.def_static("operator delete[]_", (void (*)(void *)) &HLRAppli_ReflectLines::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAppli_ReflectLines.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAppli_ReflectLines::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAppli_ReflectLines.def_static("operator delete_", (void (*)(void *, void *)) &HLRAppli_ReflectLines::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAppli_ReflectLines.def("SetAxes", (void (HLRAppli_ReflectLines::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRAppli_ReflectLines::SetAxes, "Sets the normal to the plane of visualisation, the coordinates of the view point and the coordinates of the vertical direction vector.", py::arg("Nx"), py::arg("Ny"), py::arg("Nz"), py::arg("XAt"), py::arg("YAt"), py::arg("ZAt"), py::arg("XUp"), py::arg("YUp"), py::arg("ZUp"));
cls_HLRAppli_ReflectLines.def("Perform", (void (HLRAppli_ReflectLines::*)()) &HLRAppli_ReflectLines::Perform, "None");
cls_HLRAppli_ReflectLines.def("GetResult", (TopoDS_Shape (HLRAppli_ReflectLines::*)() const) &HLRAppli_ReflectLines::GetResult, "returns resulting compound of reflect lines represented by edges in 3d");
cls_HLRAppli_ReflectLines.def("GetCompoundOf3dEdges", (TopoDS_Shape (HLRAppli_ReflectLines::*)(const HLRBRep_TypeOfResultingEdge, const Standard_Boolean, const Standard_Boolean) const) &HLRAppli_ReflectLines::GetCompoundOf3dEdges, "returns resulting compound of lines of specified type and visibility represented by edges in 3d or 2d", py::arg("type"), py::arg("visible"), py::arg("In3d"));

// Enums

}