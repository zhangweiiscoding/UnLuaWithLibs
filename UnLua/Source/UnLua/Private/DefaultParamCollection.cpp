// Tencent is pleased to support the open source community by making UnLua available.
// 
// Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the MIT License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.

#include "DefaultParamCollection.h"
#include "CoreUObject.h"

TMap<FName, FFunctionCollection> GDefaultParamCollection;

#pragma optimize("", off)

void CreateDefaultParamCollection()
{
    static bool CollectionCreated = false;
    if (!CollectionCreated)
    {
        CollectionCreated = true;

#include "DefaultParamCollection.inl"
    }
}

#pragma optimize("", on)

void DestroyDefaultParamCollection()
{
    for (TMap<FName, FFunctionCollection>::TIterator FCIt(GDefaultParamCollection); FCIt; ++FCIt)
    {
        FFunctionCollection &FunctionCollection = FCIt.Value();
        for (TMap<FName, FParameterCollection>::TIterator PCIt(FunctionCollection.Functions); PCIt; ++PCIt)
        {
            FParameterCollection &ParamCollection = PCIt.Value();
            for (TMap<FName, IParamValue*>::TIterator PVIt(ParamCollection.Parameters); PVIt; ++PVIt)
            {
                IParamValue *ParamValue = PVIt.Value();
                delete ParamValue;
            }
            ParamCollection.Parameters.Empty();
        }
        FunctionCollection.Functions.Empty();
    }
    GDefaultParamCollection.Empty();
}
