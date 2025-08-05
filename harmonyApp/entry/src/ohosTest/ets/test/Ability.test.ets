import { describe, it, expect } from '@ohos/hypium';
import { abilityDelegatorRegistry } from '@kit.TestKit';

const delegator: abilityDelegatorRegistry.AbilityDelegator =
  abilityDelegatorRegistry.getAbilityDelegator()
const bundleName = abilityDelegatorRegistry.getArguments().bundleName;

function sleep(time: number) {
  return new Promise<void>((resolve: Function) => setTimeout(resolve, time));
}

function startComposeSample() {
  return async (done: Function) => {
    await delegator.startAbility({
      bundleName: bundleName,
      abilityName: 'EntryAbility'
    });
    await sleep(5000);
    const topAbility = await delegator.getCurrentTopAbility()
    expect(topAbility.context.abilityInfo.name).assertEqual('EntryAbility');
    done();
  };
}

export default function abilityTest() {
  describe('tester', () => {
    it('starts compose sample', 0, startComposeSample());
  })
}
