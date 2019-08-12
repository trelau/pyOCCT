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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESEntity.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Graph.hxx>
#include <IFSelect_PacketList.hxx>
#include <IGESSelect_ViewSorter.hxx>
#include <Standard_Type.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <TColStd_SequenceOfInteger.hxx>

void bind_IGESSelect_ViewSorter(py::module &mod){

py::class_<IGESSelect_ViewSorter, opencascade::handle<IGESSelect_ViewSorter>, Standard_Transient> cls_IGESSelect_ViewSorter(mod, "IGESSelect_ViewSorter", "Sorts IGES Entities on the views and drawings. In a first step, it splits a set of entities according the different views they are attached to. Then, packets according single views (+ drawing frames), or according drawings (which refer to the views) can be determined");

// Constructors
cls_IGESSelect_ViewSorter.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_ViewSorter.def("SetModel", (void (IGESSelect_ViewSorter::*)(const opencascade::handle<IGESData_IGESModel> &)) &IGESSelect_ViewSorter::SetModel, "Sets the Model (for PacketList)", py::arg("model"));
cls_IGESSelect_ViewSorter.def("Clear", (void (IGESSelect_ViewSorter::*)()) &IGESSelect_ViewSorter::Clear, "Clears recorded data");
cls_IGESSelect_ViewSorter.def("Add", (Standard_Boolean (IGESSelect_ViewSorter::*)(const opencascade::handle<Standard_Transient> &)) &IGESSelect_ViewSorter::Add, "Adds an item according its type : AddEntity,AddList,AddModel", py::arg("ent"));
cls_IGESSelect_ViewSorter.def("AddEntity", (Standard_Boolean (IGESSelect_ViewSorter::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESSelect_ViewSorter::AddEntity, "Adds an IGES entity. Records the view it is attached to. Records directly <ent> if it is a ViewKindEntity or a Drawing Returns True if added, False if already in the map", py::arg("igesent"));
cls_IGESSelect_ViewSorter.def("AddList", (void (IGESSelect_ViewSorter::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IGESSelect_ViewSorter::AddList, "Adds a list of entities by adding each of the items", py::arg("list"));
cls_IGESSelect_ViewSorter.def("AddModel", (void (IGESSelect_ViewSorter::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IGESSelect_ViewSorter::AddModel, "Adds all the entities contained in a Model", py::arg("model"));
cls_IGESSelect_ViewSorter.def("NbEntities", (Standard_Integer (IGESSelect_ViewSorter::*)() const) &IGESSelect_ViewSorter::NbEntities, "Returns the count of already recorded");
cls_IGESSelect_ViewSorter.def("SortSingleViews", (void (IGESSelect_ViewSorter::*)(const Standard_Boolean)) &IGESSelect_ViewSorter::SortSingleViews, "Prepares the result to keep only sets attached to Single Views If <alsoframes> is given True, it keeps also the Drawings as specific sets, in order to get their frames. Entities attached to no single view are put in Remaining List.", py::arg("alsoframes"));
cls_IGESSelect_ViewSorter.def("SortDrawings", (void (IGESSelect_ViewSorter::*)(const Interface_Graph &)) &IGESSelect_ViewSorter::SortDrawings, "Prepares the result to the sets attached to Drawings : All the single views referenced by a Drawing become bound to the set for this Drawing", py::arg("G"));
cls_IGESSelect_ViewSorter.def("NbSets", (Standard_Integer (IGESSelect_ViewSorter::*)(const Standard_Boolean) const) &IGESSelect_ViewSorter::NbSets, "Returns the count of sets recorded, one per distinct item. The Remaining List is not counted. If <final> is False, the sets are attached to distinct views determined by the method Add. If <final> is True, they are the sets determined by the last call to, either SortSingleViews, or SortDrawings.", py::arg("final"));
cls_IGESSelect_ViewSorter.def("SetItem", (opencascade::handle<IGESData_IGESEntity> (IGESSelect_ViewSorter::*)(const Standard_Integer, const Standard_Boolean) const) &IGESSelect_ViewSorter::SetItem, "Returns the Item which is attached to a set of entities For <final> and definition of sets, see method NbSets. This item can be a kind of View or a Drawing", py::arg("num"), py::arg("final"));
cls_IGESSelect_ViewSorter.def("Sets", (opencascade::handle<IFSelect_PacketList> (IGESSelect_ViewSorter::*)(const Standard_Boolean) const) &IGESSelect_ViewSorter::Sets, "Returns the complete content of the determined Sets, which include Duplicated and Remaining (duplication 0) lists For <final> and definition of sets, see method NbSets.", py::arg("final"));
cls_IGESSelect_ViewSorter.def_static("get_type_name_", (const char * (*)()) &IGESSelect_ViewSorter::get_type_name, "None");
cls_IGESSelect_ViewSorter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_ViewSorter::get_type_descriptor, "None");
cls_IGESSelect_ViewSorter.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_ViewSorter::*)() const) &IGESSelect_ViewSorter::DynamicType, "None");

// Enums

}