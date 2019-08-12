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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <Extrema_LocateExtPC.hxx>
#include <BRepMesh_EdgeParameterProvider.hxx>

void bind_BRepMesh_EdgeParameterProvider(py::module &mod){

py::class_<BRepMesh_EdgeParameterProvider, std::unique_ptr<BRepMesh_EdgeParameterProvider, Deleter<BRepMesh_EdgeParameterProvider>>> cls_BRepMesh_EdgeParameterProvider(mod, "BRepMesh_EdgeParameterProvider", "Auxiliary class provides correct parameters on curve regarding SameParameter flag.");

// Constructors
// cls_BRepMesh_EdgeParameterProvider.def(py::init<const TopoDS_Edge &, const TopoDS_Face &, const opencascade::handle<TColStd_HArray1OfReal> &>(), py::arg("theEdge"), py::arg("theFace"), py::arg("theParameters"));

// Fields

// Methods
// cls_BRepMesh_EdgeParameterProvider.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_EdgeParameterProvider::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_EdgeParameterProvider.def_static("operator delete_", (void (*)(void *)) &BRepMesh_EdgeParameterProvider::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_EdgeParameterProvider.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_EdgeParameterProvider::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_EdgeParameterProvider.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_EdgeParameterProvider::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_EdgeParameterProvider.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_EdgeParameterProvider::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_EdgeParameterProvider.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_EdgeParameterProvider::operator delete, "None", py::arg(""), py::arg(""));
// cls_BRepMesh_EdgeParameterProvider.def("Parameter", (Standard_Real (BRepMesh_EdgeParameterProvider::*)(const Standard_Integer, const gp_Pnt &)) &BRepMesh_EdgeParameterProvider::Parameter, "Returns parameter according to SameParameter flag of the edge. If SameParameter is TRUE returns value from parameters w/o changes, elsewhere scales initial parameter and tries to determine resulting value using projection of the corresponded 3D point on PCurve.", py::arg("theIndex"), py::arg("thePoint3d"));

// Enums

}