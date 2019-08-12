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
#include <IFSelect_SelectExplore.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_TransferReader.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_Graph.hxx>
#include <Interface_EntityIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TopoDS_Shape.hxx>
#include <Transfer_TransientProcess.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <XSControl_ConnectedShapes.hxx>
#include <Standard_Type.hxx>

void bind_XSControl_ConnectedShapes(py::module &mod){

py::class_<XSControl_ConnectedShapes, opencascade::handle<XSControl_ConnectedShapes>, IFSelect_SelectExplore> cls_XSControl_ConnectedShapes(mod, "XSControl_ConnectedShapes", "From a TopoDS_Shape, or from the entity which has produced it, searches for the shapes, and the entities which have produced them in last transfer, which are adjacent to it by VERTICES");

// Constructors
cls_XSControl_ConnectedShapes.def(py::init<>());
cls_XSControl_ConnectedShapes.def(py::init<const opencascade::handle<XSControl_TransferReader> &>(), py::arg("TR"));

// Fields

// Methods
cls_XSControl_ConnectedShapes.def("SetReader", (void (XSControl_ConnectedShapes::*)(const opencascade::handle<XSControl_TransferReader> &)) &XSControl_ConnectedShapes::SetReader, "Sets a TransferReader to sort entities : it brings the TransferProcess which may change, while the TransferReader does not", py::arg("TR"));
cls_XSControl_ConnectedShapes.def("Explore", (Standard_Boolean (XSControl_ConnectedShapes::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &XSControl_ConnectedShapes::Explore, "Explores an entity : entities from which are connected to that produced by this entity, including itself", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_XSControl_ConnectedShapes.def("ExploreLabel", (TCollection_AsciiString (XSControl_ConnectedShapes::*)() const) &XSControl_ConnectedShapes::ExploreLabel, "Returns a text defining the criterium. 'Connected Entities through produced Shapes'");
cls_XSControl_ConnectedShapes.def_static("AdjacentEntities_", (opencascade::handle<TColStd_HSequenceOfTransient> (*)(const TopoDS_Shape &, const opencascade::handle<Transfer_TransientProcess> &, const TopAbs_ShapeEnum)) &XSControl_ConnectedShapes::AdjacentEntities, "This functions considers a shape from a transfer and performs the search function explained above", py::arg("ashape"), py::arg("TP"), py::arg("type"));
cls_XSControl_ConnectedShapes.def_static("get_type_name_", (const char * (*)()) &XSControl_ConnectedShapes::get_type_name, "None");
cls_XSControl_ConnectedShapes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSControl_ConnectedShapes::get_type_descriptor, "None");
cls_XSControl_ConnectedShapes.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSControl_ConnectedShapes::*)() const) &XSControl_ConnectedShapes::DynamicType, "None");

// Enums

}