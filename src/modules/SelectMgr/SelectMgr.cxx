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

void bind_SelectMgr_StateOfSelection(py::module &);
void bind_SelectMgr_TypeOfBVHUpdate(py::module &);
void bind_SelectMgr_TypeOfUpdate(py::module &);
void bind_SelectMgr_PickingStrategy(py::module &);
void bind_SelectMgr_IndexedMapOfOwner(py::module &);
void bind_SelectMgr_SensitiveEntity(py::module &);
void bind_SelectMgr_Selection(py::module &);
void bind_SelectMgr_SequenceOfSelection(py::module &);
void bind_SelectMgr_SequenceOfOwner(py::module &);
void bind_SelectMgr_SelectableObject(py::module &);
void bind_SelectMgr_EntityOwner(py::module &);
void bind_SelectMgr_SortCriterion(py::module &);
void bind_SelectMgr_IndexedDataMapOfOwnerCriterion(py::module &);
void bind_SelectMgr_Vec3(py::module &);
void bind_SelectMgr_Vec4(py::module &);
void bind_SelectMgr_Mat4(py::module &);
void bind_SelectMgr_FrustumBuilder(py::module &);
void bind_SelectMgr_BaseFrustum(py::module &);
void bind_SelectMgr_ViewClipRange(py::module &);
void bind_SelectMgr_RectangularFrustum(py::module &);
void bind_SelectMgr_TriangularFrustum(py::module &);
void bind_SelectMgr_TriangFrustums(py::module &);
void bind_SelectMgr_TriangFrustumsIter(py::module &);
void bind_SelectMgr_TriangularFrustumSet(py::module &);
void bind_SelectMgr_SelectingVolumeManager(py::module &);
void bind_SelectMgr_SelectableObjectSet(py::module &);
void bind_SelectMgr_ToleranceMap(py::module &);
void bind_SelectMgr_MapOfObjectSensitives(py::module &);
void bind_SelectMgr_MapOfObjectSensitivesIterator(py::module &);
void bind_SelectMgr_FrustumCache(py::module &);
void bind_SelectMgr_ViewerSelector(py::module &);
void bind_SelectMgr_Filter(py::module &);
void bind_SelectMgr_ListOfFilter(py::module &);
void bind_SelectMgr_ListIteratorOfListOfFilter(py::module &);
void bind_SelectMgr_CompositionFilter(py::module &);
void bind_SelectMgr_AndFilter(py::module &);
void bind_SelectMgr_OrFilter(py::module &);
void bind_SelectMgr_SOPtr(py::module &);
void bind_SelectMgr_SequenceOfSelector(py::module &);
void bind_SelectMgr_DataMapOfObjectSelectors(py::module &);
void bind_SelectMgr_DataMapIteratorOfDataMapOfObjectSelectors(py::module &);
void bind_SelectMgr_SelectionManager(py::module &);
void bind_SelectMgr_IndexedMapOfHSensitive(py::module &);
void bind_SelectMgr_SensitiveEntitySet(py::module &);
void bind_SelectMgr_SequenceOfFilter(py::module &);

PYBIND11_MODULE(SelectMgr, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.SelectBasics");
py::module::import("OCCT.PrsMgr");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.V3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.Precision");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Select3D");
py::module::import("OCCT.BVH");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TopAbs");

bind_SelectMgr_StateOfSelection(mod);
bind_SelectMgr_TypeOfBVHUpdate(mod);
bind_SelectMgr_TypeOfUpdate(mod);
bind_SelectMgr_PickingStrategy(mod);
bind_SelectMgr_IndexedMapOfOwner(mod);
bind_SelectMgr_SensitiveEntity(mod);
bind_SelectMgr_Selection(mod);
bind_SelectMgr_SequenceOfSelection(mod);
bind_SelectMgr_SequenceOfOwner(mod);
bind_SelectMgr_SelectableObject(mod);
bind_SelectMgr_EntityOwner(mod);
bind_SelectMgr_SortCriterion(mod);
bind_SelectMgr_IndexedDataMapOfOwnerCriterion(mod);
bind_SelectMgr_Vec3(mod);
bind_SelectMgr_Vec4(mod);
bind_SelectMgr_Mat4(mod);
bind_SelectMgr_FrustumBuilder(mod);
bind_SelectMgr_BaseFrustum(mod);
bind_SelectMgr_ViewClipRange(mod);
bind_SelectMgr_RectangularFrustum(mod);
bind_SelectMgr_TriangularFrustum(mod);
bind_SelectMgr_TriangFrustums(mod);
bind_SelectMgr_TriangFrustumsIter(mod);
bind_SelectMgr_TriangularFrustumSet(mod);
bind_SelectMgr_SelectingVolumeManager(mod);
bind_SelectMgr_SelectableObjectSet(mod);
bind_SelectMgr_ToleranceMap(mod);
bind_SelectMgr_MapOfObjectSensitives(mod);
bind_SelectMgr_MapOfObjectSensitivesIterator(mod);
bind_SelectMgr_FrustumCache(mod);
bind_SelectMgr_ViewerSelector(mod);
bind_SelectMgr_Filter(mod);
bind_SelectMgr_ListOfFilter(mod);
bind_SelectMgr_ListIteratorOfListOfFilter(mod);
bind_SelectMgr_CompositionFilter(mod);
bind_SelectMgr_AndFilter(mod);
bind_SelectMgr_OrFilter(mod);
bind_SelectMgr_SOPtr(mod);
bind_SelectMgr_SequenceOfSelector(mod);
bind_SelectMgr_DataMapOfObjectSelectors(mod);
bind_SelectMgr_DataMapIteratorOfDataMapOfObjectSelectors(mod);
bind_SelectMgr_SelectionManager(mod);
bind_SelectMgr_IndexedMapOfHSensitive(mod);
bind_SelectMgr_SensitiveEntitySet(mod);
bind_SelectMgr_SequenceOfFilter(mod);

}
