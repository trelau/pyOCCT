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
#include <BRepFeat_Form.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepFeat_MakePipe.hxx>

void bind_BRepFeat_MakePipe(py::module &mod){

py::class_<BRepFeat_MakePipe, std::unique_ptr<BRepFeat_MakePipe>, BRepFeat_Form> cls_BRepFeat_MakePipe(mod, "BRepFeat_MakePipe", "Constructs compound shapes with pipe features. These can be depressions or protrusions. The semantics of pipe feature creation is based on the construction of shapes: - along a length - up to a limiting face - from a limiting face to a height. The shape defining construction of the pipe feature can be either the supporting edge or the concerned area of a face. In case of the supporting edge, this contour can be attached to a face of the basis shape by binding. When the contour is bound to this face, the information that the contour will slide on the face becomes available to the relevant class methods. In case of the concerned area of a face, you could, for example, cut it out and move it to a different height which will define the limiting face of a protrusion or depression.");

// Constructors
cls_BRepFeat_MakePipe.def(py::init<>());
cls_BRepFeat_MakePipe.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Wire &, const Standard_Integer, const Standard_Boolean>(), py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Spine"), py::arg("Fuse"), py::arg("Modify"));

// Fields

// Methods
// cls_BRepFeat_MakePipe.def_static("operator new_", (void * (*)(size_t)) &BRepFeat_MakePipe::operator new, "None", py::arg("theSize"));
// cls_BRepFeat_MakePipe.def_static("operator delete_", (void (*)(void *)) &BRepFeat_MakePipe::operator delete, "None", py::arg("theAddress"));
// cls_BRepFeat_MakePipe.def_static("operator new[]_", (void * (*)(size_t)) &BRepFeat_MakePipe::operator new[], "None", py::arg("theSize"));
// cls_BRepFeat_MakePipe.def_static("operator delete[]_", (void (*)(void *)) &BRepFeat_MakePipe::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFeat_MakePipe.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFeat_MakePipe::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFeat_MakePipe.def_static("operator delete_", (void (*)(void *, void *)) &BRepFeat_MakePipe::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFeat_MakePipe.def("Init", (void (BRepFeat_MakePipe::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Wire &, const Standard_Integer, const Standard_Boolean)) &BRepFeat_MakePipe::Init, "Initializes this algorithm for adding pipes to shapes. A face Pbase is selected in the shape Sbase to serve as the basis for the pipe. It will be defined by the wire Spine. Fuse offers a choice between: - removing matter with a Boolean cut using the setting 0 - adding matter with Boolean fusion using the setting 1. The sketch face Skface serves to determine the type of operation. If it is inside the basis shape, a local operation such as glueing can be performed.", py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Spine"), py::arg("Fuse"), py::arg("Modify"));
cls_BRepFeat_MakePipe.def("Add", (void (BRepFeat_MakePipe::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakePipe::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
cls_BRepFeat_MakePipe.def("Perform", (void (BRepFeat_MakePipe::*)()) &BRepFeat_MakePipe::Perform, "None");
cls_BRepFeat_MakePipe.def("Perform", (void (BRepFeat_MakePipe::*)(const TopoDS_Shape &)) &BRepFeat_MakePipe::Perform, "None", py::arg("Until"));
cls_BRepFeat_MakePipe.def("Perform", (void (BRepFeat_MakePipe::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_MakePipe::Perform, "Assigns one of the following semantics - to a face Until - from a face From to a height Until. Reconstructs the feature topologically according to the semantic option chosen.", py::arg("From"), py::arg("Until"));
cls_BRepFeat_MakePipe.def("Curves", (void (BRepFeat_MakePipe::*)(TColGeom_SequenceOfCurve &)) &BRepFeat_MakePipe::Curves, "None", py::arg("S"));
cls_BRepFeat_MakePipe.def("BarycCurve", (opencascade::handle<Geom_Curve> (BRepFeat_MakePipe::*)()) &BRepFeat_MakePipe::BarycCurve, "None");

// Enums

}