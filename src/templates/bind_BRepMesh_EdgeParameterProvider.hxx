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
#ifndef __BRepMesh_EdgeParameterProvider__
#define __BRepMesh_EdgeParameterProvider__

#include <Standard_Transient.hxx>
#include <IMeshData_Types.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepMesh_EdgeParameterProvider.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <Extrema_LocateExtPC.hxx>

template <typename ParametersCollection>
void bind_BRepMesh_EdgeParameterProvider(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BRepMesh_EdgeParameterProvider<ParametersCollection>, opencascade::handle<BRepMesh_EdgeParameterProvider<ParametersCollection>>, Standard_Transient> cls_BRepMesh_EdgeParameterProvider(mod, name.c_str(), "Auxiliary class provides correct parameters on curve regarding SameParameter flag.", local);

// Constructors
cls_BRepMesh_EdgeParameterProvider.def(py::init<>());
cls_BRepMesh_EdgeParameterProvider.def(py::init<const IMeshData::IEdgeHandle &, const TopAbs_Orientation, const IMeshData::IFaceHandle &, const ParametersCollection &>(), py::arg("theEdge"), py::arg("theOrientation"), py::arg("theFace"), py::arg("theParameters"));

// Methods
// cls_BRepMesh_EdgeParameterProvider.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_EdgeParameterProvider<ParametersCollection>::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_EdgeParameterProvider.def_static("operator delete_", (void (*)(void *)) &BRepMesh_EdgeParameterProvider<ParametersCollection>::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_EdgeParameterProvider.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_EdgeParameterProvider<ParametersCollection>::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_EdgeParameterProvider.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_EdgeParameterProvider<ParametersCollection>::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_EdgeParameterProvider.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_EdgeParameterProvider<ParametersCollection>::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_EdgeParameterProvider.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_EdgeParameterProvider<ParametersCollection>::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_EdgeParameterProvider.def("Init", (void (BRepMesh_EdgeParameterProvider<ParametersCollection>::*)(const IMeshData::IEdgeHandle &, const TopAbs_Orientation, const IMeshData::IFaceHandle &, const ParametersCollection &)) &BRepMesh_EdgeParameterProvider<ParametersCollection>::Init, "Initialized provider by the given data.", py::arg("theEdge"), py::arg("theOrientation"), py::arg("theFace"), py::arg("theParameters"));
cls_BRepMesh_EdgeParameterProvider.def("Parameter", (Standard_Real (BRepMesh_EdgeParameterProvider<ParametersCollection>::*)(const Standard_Integer, const gp_Pnt &) const) &BRepMesh_EdgeParameterProvider<ParametersCollection>::Parameter, "Returns parameter according to SameParameter flag of the edge. If SameParameter is TRUE returns value from parameters w/o changes, elsewhere scales initial parameter and tries to determine resulting value using projection of the corresponded 3D point on PCurve.", py::arg("theIndex"), py::arg("thePoint3d"));
cls_BRepMesh_EdgeParameterProvider.def("GetPCurve", (const opencascade::handle<Adaptor2d_HCurve2d> & (BRepMesh_EdgeParameterProvider<ParametersCollection>::*)() const) &BRepMesh_EdgeParameterProvider<ParametersCollection>::GetPCurve, "Returns pcurve used to compute parameters.");

}

#endif