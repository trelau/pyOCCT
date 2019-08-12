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
#include <Standard_TypeDef.hxx>
#include <Poly_MakeLoops.hxx>
#include <NCollection_List.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <TColStd_MapIteratorOfPackedMapOfInteger.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_IndexedMap.hxx>
#include <NCollection_IncAllocator.hxx>
#include <NCollection_Sequence.hxx>

void bind_Poly_MakeLoops(py::module &mod){

py::class_<Poly_MakeLoops, std::unique_ptr<Poly_MakeLoops, Deleter<Poly_MakeLoops>>> cls_Poly_MakeLoops(mod, "Poly_MakeLoops", "Make loops from a set of connected links. A link is represented by a pair of integer indices of nodes.");

// Fields

// Methods
cls_Poly_MakeLoops.def("Reset", [](Poly_MakeLoops &self, const Poly_MakeLoops::Helper * a0) -> void { return self.Reset(a0); });
cls_Poly_MakeLoops.def("Reset", (void (Poly_MakeLoops::*)(const Poly_MakeLoops::Helper *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_MakeLoops::Reset, "It is to reset the algorithm to the initial state.", py::arg("theHelper"), py::arg("theAlloc"));
cls_Poly_MakeLoops.def("AddLink", (void (Poly_MakeLoops::*)(const Poly_MakeLoops::Link &)) &Poly_MakeLoops::AddLink, "Adds a link to the set. theOrient defines which orientations of the link are allowed.", py::arg("theLink"));
cls_Poly_MakeLoops.def("ReplaceLink", (void (Poly_MakeLoops::*)(const Poly_MakeLoops::Link &, const Poly_MakeLoops::Link &)) &Poly_MakeLoops::ReplaceLink, "Replace one link with another (e.g. to change order of nodes)", py::arg("theLink"), py::arg("theNewLink"));
cls_Poly_MakeLoops.def("SetLinkOrientation", (Poly_MakeLoops::LinkFlag (Poly_MakeLoops::*)(const Poly_MakeLoops::Link &, const Poly_MakeLoops::LinkFlag)) &Poly_MakeLoops::SetLinkOrientation, "Set a new value of orientation of a link already added earlier. It can be used with LF_None to exclude the link from consideration. Returns the old value of orienation.", py::arg("theLink"), py::arg("theOrient"));
cls_Poly_MakeLoops.def("FindLink", (Poly_MakeLoops::Link (Poly_MakeLoops::*)(const Poly_MakeLoops::Link &) const) &Poly_MakeLoops::FindLink, "Find the link stored in algo by value", py::arg("theLink"));
cls_Poly_MakeLoops.def("Perform", (Standard_Integer (Poly_MakeLoops::*)()) &Poly_MakeLoops::Perform, "Does the work. Returns the collection of result codes");
cls_Poly_MakeLoops.def("GetNbLoops", (Standard_Integer (Poly_MakeLoops::*)() const) &Poly_MakeLoops::GetNbLoops, "Returns the number of loops in the result");
cls_Poly_MakeLoops.def("GetLoop", (const Poly_MakeLoops::Loop & (Poly_MakeLoops::*)(Standard_Integer) const) &Poly_MakeLoops::GetLoop, "Returns the loop of the given index", py::arg("theIndex"));
cls_Poly_MakeLoops.def("GetNbHanging", (Standard_Integer (Poly_MakeLoops::*)() const) &Poly_MakeLoops::GetNbHanging, "Returns the number of detected hanging chains");
cls_Poly_MakeLoops.def("GetHangingLinks", (void (Poly_MakeLoops::*)(Poly_MakeLoops::ListOfLink &) const) &Poly_MakeLoops::GetHangingLinks, "Fills in the list of hanging links", py::arg("theLinks"));

// Enums
py::enum_<Poly_MakeLoops::LinkFlag>(cls_Poly_MakeLoops, "LinkFlag", "Orientation flags that can be attached to a link")
	.value("LF_None", Poly_MakeLoops::LinkFlag::LF_None)
	.value("LF_Fwd", Poly_MakeLoops::LinkFlag::LF_Fwd)
	.value("LF_Rev", Poly_MakeLoops::LinkFlag::LF_Rev)
	.value("LF_Both", Poly_MakeLoops::LinkFlag::LF_Both)
	.value("LF_Reversed", Poly_MakeLoops::LinkFlag::LF_Reversed)
	.export_values();
py::enum_<Poly_MakeLoops::ResultCode>(cls_Poly_MakeLoops, "ResultCode", "None")
	.value("RC_LoopsDone", Poly_MakeLoops::ResultCode::RC_LoopsDone)
	.value("RC_HangingLinks", Poly_MakeLoops::ResultCode::RC_HangingLinks)
	.value("RC_Failure", Poly_MakeLoops::ResultCode::RC_Failure)
	.export_values();

}