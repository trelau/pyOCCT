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

void bind_BOPDS_PDS(py::module &);
void bind_BOPDS_Pave(py::module &);
void bind_BOPDS_ListOfPave(py::module &);
void bind_BOPDS_ListIteratorOfListOfPave(py::module &);
void bind_BOPDS_ListOfPaveBlock(py::module &);
void bind_BOPDS_ListIteratorOfListOfPaveBlock(py::module &);
void bind_BOPDS_PaveBlock(py::module &);
void bind_BOPDS_DataMapOfPaveBlockListOfPaveBlock(py::module &);
void bind_BOPDS_DataMapIteratorOfDataMapOfPaveBlockListOfPaveBlock(py::module &);
void bind_BOPDS_IndexedDataMapOfPaveBlockListOfInteger(py::module &);
void bind_BOPDS_CoupleOfPaveBlocks(py::module &);
void bind_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks(py::module &);
void bind_BOPDS_IndexedMapOfPaveBlock(py::module &);
void bind_BOPDS_Pair(py::module &);
void bind_BOPDS_PairMapHasher(py::module &);
void bind_BOPDS_MapOfPair(py::module &);
void bind_BOPDS_MapIteratorOfMapOfPair(py::module &);
void bind_BOPDS_MapOfPaveBlock(py::module &);
void bind_BOPDS_MapIteratorOfMapOfPaveBlock(py::module &);
void bind_BOPDS_PIterator(py::module &);
void bind_BOPDS_Curve(py::module &);
void bind_BOPDS_VectorOfCurve(py::module &);
void bind_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock(py::module &);
void bind_BOPDS_CommonBlock(py::module &);
void bind_BOPDS_DataMapOfIntegerListOfPaveBlock(py::module &);
void bind_BOPDS_DataMapOfPaveBlockCommonBlock(py::module &);
void bind_BOPDS_DataMapIteratorOfDataMapOfPaveBlockCommonBlock(py::module &);
void bind_BOPDS_DataMapOfPaveBlockListOfInteger(py::module &);
void bind_BOPDS_DataMapIteratorOfDataMapOfPaveBlockListOfInteger(py::module &);
void bind_BOPDS_DataMapOfShapeCoupleOfPaveBlocks(py::module &);
void bind_BOPDS_DataMapIteratorOfDataMapOfShapeCoupleOfPaveBlocks(py::module &);
void bind_BOPDS_FaceInfo(py::module &);
void bind_BOPDS_VectorOfFaceInfo(py::module &);
void bind_BOPDS_IndexRange(py::module &);
void bind_BOPDS_VectorOfIndexRange(py::module &);
void bind_BOPDS_Point(py::module &);
void bind_BOPDS_VectorOfPoint(py::module &);
void bind_BOPDS_Interf(py::module &);
void bind_BOPDS_InterfVV(py::module &);
void bind_BOPDS_InterfVE(py::module &);
void bind_BOPDS_InterfVF(py::module &);
void bind_BOPDS_InterfEE(py::module &);
void bind_BOPDS_InterfEF(py::module &);
void bind_BOPDS_InterfFF(py::module &);
void bind_BOPDS_InterfVZ(py::module &);
void bind_BOPDS_InterfEZ(py::module &);
void bind_BOPDS_InterfFZ(py::module &);
void bind_BOPDS_InterfZZ(py::module &);
void bind_BOPDS_VectorOfInterfEE(py::module &);
void bind_BOPDS_VectorOfInterfEF(py::module &);
void bind_BOPDS_VectorOfInterfEZ(py::module &);
void bind_BOPDS_VectorOfInterfFF(py::module &);
void bind_BOPDS_VectorOfInterfFZ(py::module &);
void bind_BOPDS_VectorOfInterfVE(py::module &);
void bind_BOPDS_VectorOfInterfVF(py::module &);
void bind_BOPDS_VectorOfInterfVV(py::module &);
void bind_BOPDS_VectorOfInterfVZ(py::module &);
void bind_BOPDS_VectorOfInterfZZ(py::module &);
void bind_BOPDS_VectorOfListOfPaveBlock(py::module &);
void bind_BOPDS_ShapeInfo(py::module &);
void bind_BOPDS_Tools(py::module &);
void bind_BOPDS_VectorOfShapeInfo(py::module &);
void bind_BOPDS_DS(py::module &);
void bind_BOPDS_VectorOfPair(py::module &);
void bind_BOPDS_VectorOfVectorOfPair(py::module &);
void bind_BOPDS_Iterator(py::module &);
void bind_BOPDS_IteratorSI(py::module &);
void bind_BOPDS_MapOfCommonBlock(py::module &);
void bind_BOPDS_MapIteratorOfMapOfCommonBlock(py::module &);
void bind_BOPDS_PaveMapHasher(py::module &);
void bind_BOPDS_MapOfPave(py::module &);
void bind_BOPDS_MapIteratorOfMapOfPave(py::module &);
void bind_BOPDS_PIteratorSI(py::module &);
void bind_BOPDS_SubIterator(py::module &);
void bind_BOPDS_VectorOfPave(py::module &);

PYBIND11_MODULE(BOPDS, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.IntTools");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Precision");

bind_BOPDS_PDS(mod);
bind_BOPDS_Pave(mod);
bind_BOPDS_ListOfPave(mod);
bind_BOPDS_ListIteratorOfListOfPave(mod);
bind_BOPDS_ListOfPaveBlock(mod);
bind_BOPDS_ListIteratorOfListOfPaveBlock(mod);
bind_BOPDS_PaveBlock(mod);
bind_BOPDS_DataMapOfPaveBlockListOfPaveBlock(mod);
bind_BOPDS_DataMapIteratorOfDataMapOfPaveBlockListOfPaveBlock(mod);
bind_BOPDS_IndexedDataMapOfPaveBlockListOfInteger(mod);
bind_BOPDS_CoupleOfPaveBlocks(mod);
bind_BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks(mod);
bind_BOPDS_IndexedMapOfPaveBlock(mod);
bind_BOPDS_Pair(mod);
bind_BOPDS_PairMapHasher(mod);
bind_BOPDS_MapOfPair(mod);
bind_BOPDS_MapIteratorOfMapOfPair(mod);
bind_BOPDS_MapOfPaveBlock(mod);
bind_BOPDS_MapIteratorOfMapOfPaveBlock(mod);
bind_BOPDS_PIterator(mod);
bind_BOPDS_Curve(mod);
bind_BOPDS_VectorOfCurve(mod);
bind_BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock(mod);
bind_BOPDS_CommonBlock(mod);
bind_BOPDS_DataMapOfIntegerListOfPaveBlock(mod);
bind_BOPDS_DataMapOfPaveBlockCommonBlock(mod);
bind_BOPDS_DataMapIteratorOfDataMapOfPaveBlockCommonBlock(mod);
bind_BOPDS_DataMapOfPaveBlockListOfInteger(mod);
bind_BOPDS_DataMapIteratorOfDataMapOfPaveBlockListOfInteger(mod);
bind_BOPDS_DataMapOfShapeCoupleOfPaveBlocks(mod);
bind_BOPDS_DataMapIteratorOfDataMapOfShapeCoupleOfPaveBlocks(mod);
bind_BOPDS_FaceInfo(mod);
bind_BOPDS_VectorOfFaceInfo(mod);
bind_BOPDS_IndexRange(mod);
bind_BOPDS_VectorOfIndexRange(mod);
bind_BOPDS_Point(mod);
bind_BOPDS_VectorOfPoint(mod);
bind_BOPDS_Interf(mod);
bind_BOPDS_InterfVV(mod);
bind_BOPDS_InterfVE(mod);
bind_BOPDS_InterfVF(mod);
bind_BOPDS_InterfEE(mod);
bind_BOPDS_InterfEF(mod);
bind_BOPDS_InterfFF(mod);
bind_BOPDS_InterfVZ(mod);
bind_BOPDS_InterfEZ(mod);
bind_BOPDS_InterfFZ(mod);
bind_BOPDS_InterfZZ(mod);
bind_BOPDS_VectorOfInterfEE(mod);
bind_BOPDS_VectorOfInterfEF(mod);
bind_BOPDS_VectorOfInterfEZ(mod);
bind_BOPDS_VectorOfInterfFF(mod);
bind_BOPDS_VectorOfInterfFZ(mod);
bind_BOPDS_VectorOfInterfVE(mod);
bind_BOPDS_VectorOfInterfVF(mod);
bind_BOPDS_VectorOfInterfVV(mod);
bind_BOPDS_VectorOfInterfVZ(mod);
bind_BOPDS_VectorOfInterfZZ(mod);
bind_BOPDS_VectorOfListOfPaveBlock(mod);
bind_BOPDS_ShapeInfo(mod);
bind_BOPDS_Tools(mod);
bind_BOPDS_VectorOfShapeInfo(mod);
bind_BOPDS_DS(mod);
bind_BOPDS_VectorOfPair(mod);
bind_BOPDS_VectorOfVectorOfPair(mod);
bind_BOPDS_Iterator(mod);
bind_BOPDS_IteratorSI(mod);
bind_BOPDS_MapOfCommonBlock(mod);
bind_BOPDS_MapIteratorOfMapOfCommonBlock(mod);
bind_BOPDS_PaveMapHasher(mod);
bind_BOPDS_MapOfPave(mod);
bind_BOPDS_MapIteratorOfMapOfPave(mod);
bind_BOPDS_PIteratorSI(mod);
bind_BOPDS_SubIterator(mod);
bind_BOPDS_VectorOfPave(mod);

}
