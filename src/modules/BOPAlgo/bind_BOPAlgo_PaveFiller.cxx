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
#include <BOPDS_Iterator.hxx>
#include <BOPAlgo_Algo.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <BOPDS_DS.hxx>
#include <BOPDS_PDS.hxx>
#include <BOPDS_PIterator.hxx>
#include <TopTools_ListOfShape.hxx>
#include <IntTools_Context.hxx>
#include <BOPAlgo_SectionAttribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_GlueEnum.hxx>
#include <NCollection_DataMap.hxx>
#include <BOPDS_PaveBlock.hxx>
#include <Bnd_Box.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <BOPDS_IndexedDataMapOfPaveBlockListOfInteger.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <IntTools_ShrunkRange.hxx>
#include <BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <BOPDS_Curve.hxx>
#include <TColStd_DataMapOfIntegerReal.hxx>
#include <BOPDS_VectorOfCurve.hxx>
#include <TopoDS_Face.hxx>
#include <BOPDS_IndexedMapOfPaveBlock.hxx>
#include <BOPDS_MapOfPaveBlock.hxx>
#include <BOPDS_DataMapOfPaveBlockListOfPaveBlock.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BOPDS_ListOfPaveBlock.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <TopoDS_Shape.hxx>

void bind_BOPAlgo_PaveFiller(py::module &mod){

py::class_<BOPAlgo_PaveFiller, std::unique_ptr<BOPAlgo_PaveFiller>, BOPAlgo_Algo> cls_BOPAlgo_PaveFiller(mod, "BOPAlgo_PaveFiller", "The class represents the Intersection phase of the Boolean Operations algorithm. It performs the pairwise intersection of the sub-shapes of the arguments in the following order: 1. Vertex/Vertex; 2. Vertex/Edge; 3. Edge/Edge; 4. Vertex/Face; 5. Edge/Face; 6. Face/Face.");

// Constructors
cls_BOPAlgo_PaveFiller.def(py::init<>());
cls_BOPAlgo_PaveFiller.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_PaveFiller.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_PaveFiller::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_PaveFiller.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_PaveFiller::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_PaveFiller.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_PaveFiller::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_PaveFiller.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_PaveFiller::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_PaveFiller.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_PaveFiller::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_PaveFiller.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_PaveFiller::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_PaveFiller.def("DS", (const BOPDS_DS & (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::DS, "None");
cls_BOPAlgo_PaveFiller.def("PDS", (BOPDS_PDS (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::PDS, "None");
// cls_BOPAlgo_PaveFiller.def("Iterator", (const BOPDS_PIterator & (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::Iterator, "None");
cls_BOPAlgo_PaveFiller.def("SetArguments", (void (BOPAlgo_PaveFiller::*)(const TopTools_ListOfShape &)) &BOPAlgo_PaveFiller::SetArguments, "None", py::arg("theLS"));
cls_BOPAlgo_PaveFiller.def("Arguments", (const TopTools_ListOfShape & (BOPAlgo_PaveFiller::*)() const) &BOPAlgo_PaveFiller::Arguments, "None");
cls_BOPAlgo_PaveFiller.def("Context", (const opencascade::handle<IntTools_Context> & (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::Context, "None");
cls_BOPAlgo_PaveFiller.def("SetSectionAttribute", (void (BOPAlgo_PaveFiller::*)(const BOPAlgo_SectionAttribute &)) &BOPAlgo_PaveFiller::SetSectionAttribute, "None", py::arg("theSecAttr"));
cls_BOPAlgo_PaveFiller.def("SetNonDestructive", (void (BOPAlgo_PaveFiller::*)(const Standard_Boolean)) &BOPAlgo_PaveFiller::SetNonDestructive, "Sets the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.", py::arg("theFlag"));
cls_BOPAlgo_PaveFiller.def("NonDestructive", (Standard_Boolean (BOPAlgo_PaveFiller::*)() const) &BOPAlgo_PaveFiller::NonDestructive, "Returns the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.");
cls_BOPAlgo_PaveFiller.def("Perform", (void (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::Perform, "None");
cls_BOPAlgo_PaveFiller.def("SetGlue", (void (BOPAlgo_PaveFiller::*)(const BOPAlgo_GlueEnum)) &BOPAlgo_PaveFiller::SetGlue, "Sets the glue option for the algorithm", py::arg("theGlue"));
cls_BOPAlgo_PaveFiller.def("Glue", (BOPAlgo_GlueEnum (BOPAlgo_PaveFiller::*)() const) &BOPAlgo_PaveFiller::Glue, "Returns the glue option of the algorithm");
cls_BOPAlgo_PaveFiller.def("SetAvoidBuildPCurve", (void (BOPAlgo_PaveFiller::*)(const Standard_Boolean)) &BOPAlgo_PaveFiller::SetAvoidBuildPCurve, "Sets the flag to avoid building of p-curves of edges on faces", py::arg("theValue"));
cls_BOPAlgo_PaveFiller.def("IsAvoidBuildPCurve", (Standard_Boolean (BOPAlgo_PaveFiller::*)() const) &BOPAlgo_PaveFiller::IsAvoidBuildPCurve, "Returns the flag to avoid building of p-curves of edges on faces");

// Enums

}