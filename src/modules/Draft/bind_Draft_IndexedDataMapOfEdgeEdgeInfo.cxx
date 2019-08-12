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
#include <NCollection_IndexedDataMap.hxx>
#include <TopoDS_Edge.hxx>
#include <Draft_EdgeInfo.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <Draft_IndexedDataMapOfEdgeEdgeInfo.hxx>

#include <bind_NCollection_IndexedDataMap.hxx>

void bind_Draft_IndexedDataMapOfEdgeEdgeInfo(py::module &mod){

bind_NCollection_IndexedDataMap<TopoDS_Edge, Draft_EdgeInfo, TopTools_ShapeMapHasher>(mod, "Draft_IndexedDataMapOfEdgeEdgeInfo", py::module_local(false));

}