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
#include <BRepAlgo_AsDes.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <BRepOffset_Offset.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepOffset_Inter2d.hxx>

void bind_BRepOffset_Inter2d(py::module &mod){

py::class_<BRepOffset_Inter2d, std::unique_ptr<BRepOffset_Inter2d>> cls_BRepOffset_Inter2d(mod, "BRepOffset_Inter2d", "Computes the intersections betwwen edges on a face stores result is SD as AsDes from BRepOffset.");

// Constructors

// Fields

// Methods
// cls_BRepOffset_Inter2d.def_static("operator new_", (void * (*)(size_t)) &BRepOffset_Inter2d::operator new, "None", py::arg("theSize"));
// cls_BRepOffset_Inter2d.def_static("operator delete_", (void (*)(void *)) &BRepOffset_Inter2d::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffset_Inter2d.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffset_Inter2d::operator new[], "None", py::arg("theSize"));
// cls_BRepOffset_Inter2d.def_static("operator delete[]_", (void (*)(void *)) &BRepOffset_Inter2d::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffset_Inter2d.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffset_Inter2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffset_Inter2d.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffset_Inter2d::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffset_Inter2d.def_static("Compute_", (void (*)(const opencascade::handle<BRepAlgo_AsDes> &, const TopoDS_Face &, const TopTools_IndexedMapOfShape &, const Standard_Real, TopTools_IndexedDataMapOfShapeListOfShape &)) &BRepOffset_Inter2d::Compute, "Computes the intersections between the edges stored is AsDes as descendants of <F> . Intersections is computed between two edges if one of them is bound in NewEdges. When all faces of the shape are treated the intersection vertices have to be fused using the FuseVertices method. theDMVV contains the vertices that should be fused", py::arg("AsDes"), py::arg("F"), py::arg("NewEdges"), py::arg("Tol"), py::arg("theDMVV"));
cls_BRepOffset_Inter2d.def_static("ConnexIntByInt_", (void (*)(const TopoDS_Face &, BRepOffset_Offset &, TopTools_DataMapOfShapeShape &, const TopTools_DataMapOfShapeShape &, const opencascade::handle<BRepAlgo_AsDes> &, const Standard_Real, const Standard_Real, TopTools_IndexedMapOfShape &, TopTools_IndexedDataMapOfShapeListOfShape &)) &BRepOffset_Inter2d::ConnexIntByInt, "Computes the intersection between the offset edges of the <FI>. All intersection vertices will be stored in AsDes2d. When all faces of the shape are treated the intersection vertices have to be fused using the FuseVertices method. theDMVV contains the vertices that should be fused.", py::arg("FI"), py::arg("OFI"), py::arg("MES"), py::arg("Build"), py::arg("AsDes2d"), py::arg("Offset"), py::arg("Tol"), py::arg("FacesWithVerts"), py::arg("theDMVV"));
cls_BRepOffset_Inter2d.def_static("ConnexIntByIntInVert_", (void (*)(const TopoDS_Face &, BRepOffset_Offset &, TopTools_DataMapOfShapeShape &, const TopTools_DataMapOfShapeShape &, const opencascade::handle<BRepAlgo_AsDes> &, const opencascade::handle<BRepAlgo_AsDes> &, const Standard_Real, TopTools_IndexedDataMapOfShapeListOfShape &)) &BRepOffset_Inter2d::ConnexIntByIntInVert, "Computes the intersection between the offset edges generated from vertices and stored into AsDes as descendants of the <FI>. All intersection vertices will be stored in AsDes2d. When all faces of the shape are treated the intersection vertices have to be fused using the FuseVertices method. theDMVV contains the vertices that should be fused.", py::arg("FI"), py::arg("OFI"), py::arg("MES"), py::arg("Build"), py::arg("AsDes"), py::arg("AsDes2d"), py::arg("Tol"), py::arg("theDMVV"));
cls_BRepOffset_Inter2d.def_static("FuseVertices_", (void (*)(const TopTools_IndexedDataMapOfShapeListOfShape &, const opencascade::handle<BRepAlgo_AsDes> &)) &BRepOffset_Inter2d::FuseVertices, "Fuses the chains of vertices in the theDMVV and updates AsDes by replacing the old vertices with the new ones.", py::arg("theDMVV"), py::arg("theAsDes"));
cls_BRepOffset_Inter2d.def_static("ExtentEdge_", (void (*)(const TopoDS_Edge &, TopoDS_Edge &, const Standard_Real)) &BRepOffset_Inter2d::ExtentEdge, "extents the edge", py::arg("E"), py::arg("NE"), py::arg("theOffset"));

// Enums

}