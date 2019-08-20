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
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Handle.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPTools_ConnexityBlock.hxx>

void bind_BOPTools_ConnexityBlock(py::module &mod){

py::class_<BOPTools_ConnexityBlock, std::unique_ptr<BOPTools_ConnexityBlock>> cls_BOPTools_ConnexityBlock(mod, "BOPTools_ConnexityBlock", "None");

// Constructors
cls_BOPTools_ConnexityBlock.def(py::init<>());
cls_BOPTools_ConnexityBlock.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
cls_BOPTools_ConnexityBlock.def("Shapes", (const TopTools_ListOfShape & (BOPTools_ConnexityBlock::*)() const) &BOPTools_ConnexityBlock::Shapes, "None");
cls_BOPTools_ConnexityBlock.def("ChangeShapes", (TopTools_ListOfShape & (BOPTools_ConnexityBlock::*)()) &BOPTools_ConnexityBlock::ChangeShapes, "None");
cls_BOPTools_ConnexityBlock.def("SetRegular", (void (BOPTools_ConnexityBlock::*)(const Standard_Boolean)) &BOPTools_ConnexityBlock::SetRegular, "None", py::arg("theFlag"));
cls_BOPTools_ConnexityBlock.def("IsRegular", (Standard_Boolean (BOPTools_ConnexityBlock::*)() const) &BOPTools_ConnexityBlock::IsRegular, "None");
cls_BOPTools_ConnexityBlock.def("Loops", (const TopTools_ListOfShape & (BOPTools_ConnexityBlock::*)() const) &BOPTools_ConnexityBlock::Loops, "None");
cls_BOPTools_ConnexityBlock.def("ChangeLoops", (TopTools_ListOfShape & (BOPTools_ConnexityBlock::*)()) &BOPTools_ConnexityBlock::ChangeLoops, "None");

// Enums

}