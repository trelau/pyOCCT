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
#include <Standard_Handle.hxx>
#include <IGESToBRep_AlgoContainer.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESEntity.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <IGESToBRep.hxx>

void bind_IGESToBRep(py::module &mod){

py::class_<IGESToBRep, std::unique_ptr<IGESToBRep>> cls_IGESToBRep(mod, "IGESToBRep", "Provides tools in order to transfer IGES entities to CAS.CADE.");

// Constructors

// Fields

// Methods
// cls_IGESToBRep.def_static("operator new_", (void * (*)(size_t)) &IGESToBRep::operator new, "None", py::arg("theSize"));
// cls_IGESToBRep.def_static("operator delete_", (void (*)(void *)) &IGESToBRep::operator delete, "None", py::arg("theAddress"));
// cls_IGESToBRep.def_static("operator new[]_", (void * (*)(size_t)) &IGESToBRep::operator new[], "None", py::arg("theSize"));
// cls_IGESToBRep.def_static("operator delete[]_", (void (*)(void *)) &IGESToBRep::operator delete[], "None", py::arg("theAddress"));
// cls_IGESToBRep.def_static("operator new_", (void * (*)(size_t, void *)) &IGESToBRep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESToBRep.def_static("operator delete_", (void (*)(void *, void *)) &IGESToBRep::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESToBRep.def_static("Init_", (void (*)()) &IGESToBRep::Init, "Creates and initializes default AlgoContainer.");
cls_IGESToBRep.def_static("SetAlgoContainer_", (void (*)(const opencascade::handle<IGESToBRep_AlgoContainer> &)) &IGESToBRep::SetAlgoContainer, "Sets default AlgoContainer", py::arg("aContainer"));
cls_IGESToBRep.def_static("AlgoContainer_", (opencascade::handle<IGESToBRep_AlgoContainer> (*)()) &IGESToBRep::AlgoContainer, "Returns default AlgoContainer");
cls_IGESToBRep.def_static("IsCurveAndSurface_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsCurveAndSurface, "Return True if the IGESEntity can be transfered by TransferCurveAndSurface. ex: All IGESEntity from IGESGeom", py::arg("start"));
cls_IGESToBRep.def_static("IsBasicCurve_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsBasicCurve, "Return True if the IGESEntity can be transfered by TransferBasicCurve. ex: CircularArc, ConicArc, Line, CopiousData, BSplineCurve, SplineCurve... from IGESGeom : 104,110,112,126", py::arg("start"));
cls_IGESToBRep.def_static("IsBasicSurface_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsBasicSurface, "Return True if the IGESEntity can be transfered by TransferBasicSurface. ex: BSplineSurface, SplineSurface... from IGESGeom : 114,128", py::arg("start"));
cls_IGESToBRep.def_static("IsTopoCurve_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsTopoCurve, "Return True if the IGESEntity can be transfered by TransferTopoCurve. ex: all Curves from IGESGeom : all basic curves,102,130,142,144", py::arg("start"));
cls_IGESToBRep.def_static("IsTopoSurface_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsTopoSurface, "Return True if the IGESEntity can be transfered by TransferTopoSurface. ex: All Surfaces from IGESGeom : all basic surfaces,108,118,120,122,141,143", py::arg("start"));
cls_IGESToBRep.def_static("IsBRepEntity_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsBRepEntity, "Return True if the IGESEntity can be transfered by TransferBRepEntity. ex: VertexList, EdgeList, Loop, Face, Shell, Manifold Solid BRep Object from IGESSolid : 502, 504, 508, 510, 514, 186.", py::arg("start"));
cls_IGESToBRep.def_static("IGESCurveToSequenceOfIGESCurve_", (Standard_Integer (*)(const opencascade::handle<IGESData_IGESEntity> &, opencascade::handle<TColStd_HSequenceOfTransient> &)) &IGESToBRep::IGESCurveToSequenceOfIGESCurve, "None", py::arg("curve"), py::arg("sequence"));
cls_IGESToBRep.def_static("TransferPCurve_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Face &)) &IGESToBRep::TransferPCurve, "None", py::arg("fromedge"), py::arg("toedge"), py::arg("face"));

// Enums

}